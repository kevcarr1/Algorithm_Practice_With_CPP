#ifndef STATS_H
#define STATS_H

#include <string>
#include <map>
#include <vector>
#include <ctime>

struct AlgorithmStat {
    time_t lastPracticedAt = 0;
    time_t lastPassedAt = 0;
    int consecutiveFails = 0;
    int failsBeforeLastPass = 0;
};

// Difficulty for each known algorithm
extern const std::map<std::string, std::string> ALGORITHM_DIFFICULTY;

class Stats {
public:
    void load(const std::string& path);
    void save(const std::string& path) const;
    void writeDashboard(const std::string& jsPath) const;
    void recordResult(const std::string& algorithm, bool passed);
    double getDecayScore(const std::string& algorithm) const;
    std::vector<std::string> getDueForReview() const;

private:
    std::map<std::string, AlgorithmStat> data;
    double getEffectiveHalfLifeDays(const std::string& algorithm) const;
};

#endif
