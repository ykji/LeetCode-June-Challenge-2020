class Solution {
public:
    string longestDupSubstring(string str)
    {
        std::string_view ans;
        std::unordered_set<std::string_view> SET;
        size_t b = 1;
        size_t last = str.size() - 1;
        while (b <= last)
        {
            auto len = b + (last - b) / 2;
            bool found = false;
            for (size_t i = 0; i != str.size() - len + 1; ++i)
            {
                const auto [it, inserted] = SET.emplace(str.data() + i, len);
                if (!inserted)
                {
                    found = true;
                    ans = *it;
                    break;
                }
            }

            if (found)
                b = len + 1;
            else
                last = len - 1;

            SET.clear();
        }

        return {ans.begin(), ans.end()};
    }
};
