//
// Created by addy on 15/11/20.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <iterator>
template<typename vector_type>
inline void display_vector(std::vector<vector_type>& vec) {
    for(auto it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout<<"\n";
}

template <typename vector_type>
void remove_elements(std::vector<vector_type>& vec,
                              ) {

}

template<typename vector_type>
int remove_duplicates_sorted_vector(std::vector<vector_type>& vec) {
    for(auto it = vec.begin(); it != vec.end(); it++) {

    }
    return vec.size();
}

template<typename vector_type>
void find_duplicates_test(std::vector<vector_type>& vec) {
    std::map<vector_type, int> countMap;
    for(auto it = vec.begin(); it != vec.end(); it++) {
        assert(countMap.find(*it) != countMap.end());
        countMap[*it] = 1;
    }
}

int main() {
    std::vector<int> sample ={1,1,2};
            //{0,0,1,1,1,2,2,3,3,4};
            //{1,1,2};
    //{1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10};
    std::vector<int> sample_sorted = sample;
    std::sort(sample_sorted.begin(), sample_sorted.end());
    std::cout << "Sorted vector with duplicates" << "\n";
    display_vector(sample_sorted);
    int newSize = remove_duplicates_sorted_vector(sample_sorted);
    //find_duplicates_test(sample_sorted);
    //std::cout << "Number of duplicates removed " << deletions << "\n";
    std::cout << "Vector state \n";
    display_vector(sample_sorted);
}
