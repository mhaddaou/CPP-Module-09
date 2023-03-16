/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:08:44 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/03/15 23:27:25 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Function to perform merge-insertion sort
template<typename Iterator>
void merge_insertion_sort(Iterator first, Iterator last)
{
    const int INSERTION_SORT_THRESHOLD = 7;
    
    if (distance(first, last) <= INSERTION_SORT_THRESHOLD)
    {
        // Use insertion sort for small ranges
        sort(first, last);
    }
    else
    {
        Iterator middle = first + (distance(first, last) / 2);
        
        // Recursively sort the left and right halves
        merge_insertion_sort(first, middle);
        merge_insertion_sort(middle, last);
        
        // Merge the two sorted halves
        inplace_merge(first, middle, last);
    }
}

int main(int ac, char **av)
{
    // Create two vectors of unsorted numbers
    vector<int> vec1 = { 5, 2, 8, 4, 9 };
    vector<int> vec2 = { 7, 1, 6, 3, 0 };
    
    // Sort the first vector and measure the time taken
    clock_t start1 = clock();
    merge_insertion_sort(vec1.begin(), vec1.end());
    clock_t end1 = clock();
    double time1 = double(end1 - start1) / CLOCKS_PER_SEC;
    
    // Sort the second vector and measure the time taken
    clock_t start2 = clock();
    merge_insertion_sort(vec2.begin(), vec2.end());
    clock_t end2 = clock();
    double time2 = double(end2 - start2) / CLOCKS_PER_SEC;
    
    // Print the sorted vectors and the time taken to sort each one
    cout << "vec1: ";
    for (vector<int>::const_iterator it = vec1.begin(); it != vec1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Time taken to sort vec1: " << time1 << " seconds" << endl;
    
    cout << "vec2: ";
    for (vector<int>::const_iterator it = vec2.begin(); it != vec2.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Time taken to sort vec2: " << time2 << " seconds" << endl;
    
    return 0;
}
