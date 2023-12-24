#include <iostream>

/*
                    Q. Majority element     ( > (n/3) times)

            explanation -  arr[] = {1, 1, 1, 3, 3, 2, 2, 2},    n = 8
                            we have to return the element which appears more than floor of n/3 times
                            which means, floor value for n = 8 is -> 8/2 = 2.66
                                                             floor value = 2

                                    there are 2 integers which appears more than 2 times in the array
                                                they are - [1, 2]

            Brute force -  we take a element and traverse through the entire array

        pseudo code
ls = []                 // list
for(i=0->n-1)                                   // O(n)
{
    if(ls.size() == 0 || ls[0] != nums[i])
    {
        cnt = 0;
        for(j=0->n-1)                           // O(n)
        {
            if(nums[j] == nums[i])
                cnt++;
        }
        if(cnt > n/3)
            ls.add(nums[i]);
    }
    if(ls.size() == 2)
        break;
}
return ls;


                TC - O(N^2)
                SC - O(1)



                Better sol -  will use hashing
                            arr[] = {1, 1, 1, 1, 3, 2, 2, 2}

                            we will create a hash map and put nmbr with respect to their counter in it
                                                | 2, 3 |
                                                | 3, 1 |
                                                | 1, 4 |
                                                --------
                                                 no, cnt

                                then we go through the hash map, we get '1' which appears 4 times and '2' appears 3 times
                                so the outcome will be [1, 2],  we can store it in a list and return it
                        for better solution firstly we iterate through the array then we iterate through the hash table
                        which is not necessarily needed, instead we iterate through array and the moment an element appear
                        3 times ( > N/3) we return it as answer

        pseudo code
ls = [], map
min = (n/3) +1
for(i=0->n-1)                   // O(N)         
{
    mpp[arr[i]]++;              // when we find 'i' after a 'i' then it will get ++     // O(log N)
    if(mpp[arr[i]] == min)
        ls.add(arr[i]);
}

                TC - O(N + log N)
                SC - O(N)               // bcz we are using extra space

        Actual code
vector<int> majorityElement(vector<int> v)
{
    vector<int> ls;
    map<int, int> mpp;
    int n = v.size();
    int mini = (int)(n/3) + 1;

    for(int i = 0; i < n; i++)
    {
        mpp[v[i]]++;
        if(mpp[v[i]] == mini)
            ls.push_back(v[i]);

        if(ls.size() == 2)                      // code will stop when we get 2 o/p([1, 2]) in this case
            break;
    }
    sort(ls.begin(), ls.end());                 // O(2 log 2)
    return ls;
}


                Optimal sol -  we will use the same logic as we used in majorityElement (N/2 times), instead of N/2 we will
                                be using N/3 times in logic 

        pseudo code
>[N/3]
cnt1 = 0, cnt2 = 0              // <- for element1 and element2, bz we know there will be maximum 2 nmbr f o/p we an get
el1, el2

for(i=0->n-1)
{
    if(cnt1 == 0 && nums[i] != el2)
    {
        cnt1 = 1, el1 = nums[i]
    }
    else if(cnt2 == 0 && nums[i] != el1)
    {
        cnt2 = 1, el2 = nums[i]
    }
    else if(el1 == nums[i])
        cnt1++
    else if(el2 == nums[i])
        cnt2++

    else
        cnt1--, cnt2--
}


        Actual code
vector<int> majorityElement(vector<int> v)
{
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;

    for(int i = 0; i < v.size(); i++)               // O(N)
    {
        if(cnt1 == 0 && el2 != v[i])
        {
            cnt1 = 1;
            el1 = v[i];
        }
        else if(cnt2 == 0 && el1 != v[i])
        {
            cnt2 = 1;
            el2 = v[i];
        }
        else if(v[i] == el1)
            cnt1++;
        else if(v[i] == el2)
            cnt2++;
        else
        {
            cnt1--, cn2--;
        }
    }
    vector<int> ls;
    cnt1 = 0, cnt2 = 0;

    for(int i = 0; i < v.size(); i++)               // O(N)
    {
        if(el1 == v[i])
            cnt1++;
        if(el2 == v[i])
            cnt2++;
    }
    int mini = (int)(v.size()/3) + 1;
    
    if(cnt1 >= mini)
        ls.push_back(el1);
    if(cnt2 >= mini)
        ls.push_back(el2);

    sort(ls.begin(), ls.end());             // SC - O(1)
    return ls;
}

            
                TC - O(2N)
                SC - O(1)
*/

int main()
{
    std::cout << "Hello World!\n";
}