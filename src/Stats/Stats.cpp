#include "Stats.h"
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

const map<string, string> ALGORITHM_DIFFICULTY = {
    {"BubbleSort",      "easy"},
    {"SelectionSort",   "easy"},
    {"InsertionSort",   "easy"},
    {"MergeSort",       "medium"},
    {"QuickSort",       "medium"},
    {"HeapSort",        "hard"},
    {"TimSort",         "hard"},
    {"LinearSearch",    "easy"},
    {"HashMapSearch",   "easy"},
    {"RemoveDuplicates","easy"},
    {"SlidingWindow",   "medium"},
};

// Base half-life in days by difficulty
static double baseHalfLife(const string& difficulty)
{
    if (difficulty == "easy")   return 14.0;
    if (difficulty == "medium") return 7.0;
    return 3.0; // hard
}

// Decay multiplier based on fails before the last pass
static double failMultiplier(int fails)
{
    if (fails == 0)  return 1.5;
    if (fails <= 2)  return 1.0;
    if (fails <= 5)  return 0.7;
    return 0.4;
}

double Stats::getEffectiveHalfLifeDays(const string& algorithm) const
{
    auto diffIt = ALGORITHM_DIFFICULTY.find(algorithm);
    string difficulty = (diffIt != ALGORITHM_DIFFICULTY.end()) ? diffIt->second : "medium";
    double base = baseHalfLife(difficulty);

    auto statIt = data.find(algorithm);
    int fails = (statIt != data.end()) ? statIt->second.failsBeforeLastPass : 0;
    return base * failMultiplier(fails);
}

void Stats::recordResult(const string& algorithm, bool passed)
{
    AlgorithmStat& stat = data[algorithm];
    stat.lastPracticedAt = time(nullptr);
    if (passed) {
        stat.lastPassedAt = stat.lastPracticedAt;
        stat.failsBeforeLastPass = stat.consecutiveFails;
        stat.consecutiveFails = 0;
    } else {
        stat.consecutiveFails++;
    }
}

double Stats::getDecayScore(const string& algorithm) const
{
    auto it = data.find(algorithm);
    if (it == data.end() || it->second.lastPassedAt == 0) return 0.0;
    if (it->second.consecutiveFails > 0) return 0.0;

    double daysSince = difftime(time(nullptr), it->second.lastPassedAt) / 86400.0;
    double halfLife = getEffectiveHalfLifeDays(algorithm);
    return 100.0 * pow(0.5, daysSince / halfLife);
}

vector<string> Stats::getDueForReview() const
{
    vector<string> due;
    for (auto& [name, _] : ALGORITHM_DIFFICULTY) {
        if (getDecayScore(name) < 50.0) {
            due.push_back(name);
        }
    }
    return due;
}

// ---- Minimal JSON load ----

void Stats::load(const string& path)
{
    ifstream f(path);
    if (!f.is_open()) return;

    string content((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
    size_t pos = 0;

    auto skipWS = [&]() {
        while (pos < content.size() && isspace((unsigned char)content[pos])) pos++;
    };

    auto readString = [&]() -> string {
        skipWS();
        if (pos >= content.size() || content[pos] != '"') return "";
        pos++;
        string result;
        while (pos < content.size() && content[pos] != '"') result += content[pos++];
        pos++;
        return result;
    };

    auto readLong = [&]() -> long long {
        skipWS();
        long long v = 0;
        bool neg = false;
        if (pos < content.size() && content[pos] == '-') { neg = true; pos++; }
        while (pos < content.size() && isdigit((unsigned char)content[pos]))
            v = v * 10 + (content[pos++] - '0');
        return neg ? -v : v;
    };

    size_t algPos = content.find("\"algorithms\"");
    if (algPos == string::npos) return;
    pos = algPos + 12;

    skipWS(); if (pos < content.size() && content[pos] == ':') pos++;
    skipWS(); if (pos < content.size() && content[pos] == '{') pos++;

    while (pos < content.size()) {
        skipWS();
        if (content[pos] == '}') break;
        if (content[pos] == ',') { pos++; continue; }

        string name = readString();
        if (name.empty()) break;

        skipWS(); if (pos < content.size() && content[pos] == ':') pos++;
        skipWS(); if (pos < content.size() && content[pos] == '{') pos++;

        AlgorithmStat stat;
        while (pos < content.size()) {
            skipWS();
            if (content[pos] == '}') { pos++; break; }
            if (content[pos] == ',') { pos++; continue; }

            string key = readString();
            skipWS(); if (pos < content.size() && content[pos] == ':') pos++;

            long long val = readLong();
            if      (key == "lastPracticedAt")    stat.lastPracticedAt    = (time_t)val;
            else if (key == "lastPassedAt")       stat.lastPassedAt       = (time_t)val;
            else if (key == "consecutiveFails")   stat.consecutiveFails   = (int)val;
            else if (key == "failsBeforeLastPass") stat.failsBeforeLastPass = (int)val;
        }
        data[name] = stat;
    }
}

// ---- JSON save ----

void Stats::save(const string& path) const
{
    ofstream f(path);
    if (!f.is_open()) {
        cerr << "Warning: could not write stats to " << path << endl;
        return;
    }

    f << "{\n  \"algorithms\": {\n";
    bool first = true;
    for (auto& [name, stat] : data) {
        if (!first) f << ",\n";
        first = false;
        f << "    \"" << name << "\": {\n";
        f << "      \"lastPracticedAt\": "    << (long long)stat.lastPracticedAt    << ",\n";
        f << "      \"lastPassedAt\": "       << (long long)stat.lastPassedAt       << ",\n";
        f << "      \"consecutiveFails\": "   << stat.consecutiveFails              << ",\n";
        f << "      \"failsBeforeLastPass\": " << stat.failsBeforeLastPass          << "\n";
        f << "    }";
    }
    f << "\n  }\n}\n";
}

// ---- Dashboard JS generation ----

void Stats::writeDashboard(const string& jsPath) const
{
    ofstream f(jsPath);
    if (!f.is_open()) {
        cerr << "Warning: could not write dashboard to " << jsPath << endl;
        return;
    }

    f << "// Auto-generated by Algorithm Practice — do not edit manually\n";
    f << "const STATS = {\n  algorithms: [\n";

    bool first = true;
    for (auto& [name, difficulty] : ALGORITHM_DIFFICULTY) {
        if (!first) f << ",\n";
        first = false;

        auto it = data.find(name);
        double score     = getDecayScore(name);
        double halfLife  = getEffectiveHalfLifeDays(name);

        long long lastPracticedAt   = 0;
        long long lastPassedAt      = 0;
        int consecutiveFails        = 0;
        int failsBeforeLastPass     = 0;

        if (it != data.end()) {
            lastPracticedAt     = (long long)it->second.lastPracticedAt;
            lastPassedAt        = (long long)it->second.lastPassedAt;
            consecutiveFails    = it->second.consecutiveFails;
            failsBeforeLastPass = it->second.failsBeforeLastPass;
        }

        f << fixed << setprecision(1);
        f << "    { name: \"" << name << "\""
          << ", difficulty: \""  << difficulty   << "\""
          << ", score: "         << score
          << ", halfLifeDays: "  << halfLife
          << ", lastPracticedAt: " << lastPracticedAt
          << ", lastPassedAt: "    << lastPassedAt
          << ", consecutiveFails: "    << consecutiveFails
          << ", failsBeforeLastPass: " << failsBeforeLastPass
          << " }";
    }

    f << "\n  ]\n};\n";
}
