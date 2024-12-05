class FrequencyTracker {
    unordered_map<int, int> mp;
    unordered_map<int, int> fq;

public:
    FrequencyTracker() {}

    void add(int number) {
        if (fq[mp[number]] > 0)
            fq[mp[number]]--;
        mp[number]++;
        fq[mp[number]]++;
    }

    void deleteOne(int number) {
        if (mp[number] > 0) {
            fq[mp[number]]--;
            mp[number]--;
            fq[mp[number]]++;
        }
    }

    bool hasFrequency(int frequency) { return fq[frequency]; }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */