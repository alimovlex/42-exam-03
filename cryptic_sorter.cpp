#include <iostream>
#include <vector>
#include <string_view>
#include <algorithm>
#include <cctype>

struct StringElem {
    std::string_view str;
    int original_index;
};

// Helper function to count vowels using explicit string_view iterators
int count_vowels(std::string_view s) {
    int count = 0;
    for (auto it = s.begin(); it != s.end(); ++it) {
        char ch = std::tolower(static_cast<unsigned char>(*it));
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

// Named boolean comparator function using string_view iterators
bool compare_elems(const StringElem& ea, const StringElem& eb) {
    // 1. Primary sort: By string length (shortest first)
    if (ea.str.length() != eb.str.length()) {
        return ea.str.length() < eb.str.length();
    }

    // 2. Secondary sort: ASCII order (case-insensitive) using iterators
    auto it1 = ea.str.begin();
    auto it2 = eb.str.begin();
    for (; it1 != ea.str.end() && it2 != eb.str.end(); ++it1, ++it2) {
        char ca = std::tolower(static_cast<unsigned char>(*it1));
        char cb = std::tolower(static_cast<unsigned char>(*it2));
        if (ca != cb) {
            return ca < cb;
        }
    }

    // 3. Tertiary sort: By number of vowels (ascending)
    int v_a = count_vowels(ea.str);
    int v_b = count_vowels(eb.str);
    if (v_a != v_b) {
        return v_a < v_b;
    }

    // 4. Case-insensitivity tie-breaker: Standard ASCII order
    if (ea.str != eb.str) {
        return ea.str < eb.str;
    }

    // 5. Stable sort tie-breaker: Original input index order
    return ea.original_index < eb.original_index;
}

int main(int argc, char** argv)
{
    if (argc < 2)
        return 0;

    std::vector<StringElem> elems;
    elems.reserve(argc - 1);

    // 1. Pointer Iterators: Treat argv pointers as an iterator range [argv + 1, argv + argc)
    int index = 0;
    for (auto it = argv + 1; it != argv + argc; ++it)
        elems.push_back({ *it, index++ });

    // 2. Sorting with std::sort using vector iterators elems.begin() and elems.end()
    std::sort(elems.begin(), elems.end(), compare_elems);

    // 3. Output results using const_iterators over std::vector
    for (auto it = elems.cbegin(); it != elems.cend(); ++it)
        std::cout << it->str << std::endl;

    return 0;
}
