#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}


//here i have sorted the vector of ascii values
void sorting(vector<int>& v) {
    int n = v.size();
    for (int i=0; i<n-1; i++) {
        for (int j = 0; j<n-i-1; j++) {
            if (v[j]>v[j+1]) {
                swap(v[j], v[j+1]);
            }
        }
    }
}

// here i have taken custom inputs in my ide so that i can check for multiple inputs
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //here is the logic of reversing the words, what i have done is 
    //removing spaces at the beginning and end of the string, 
    //then reads each word one by one. When it finds a space after a word, 
    //it adds that word to the start of the result. This continues for all words, reversing their order, 
    //and then it returns the final reversed string.
    string s;
    getline(cin, s);
    int n=s.size();
    int l=0, r=s.length()-1;
    string temp, ans="";
    while(s[l]==' ')l++;
    while(s[r]==' ')r--;
    while(l<=r){
        if(s[l]!=' ')temp +=s[l];
        else if(s[l-1]==' '){
            l++;
            continue;
        }
        else{
            ans = temp+ " " + ans;
            temp="";
        }
        l++;
    }
    ans = temp+" "+ans;
    ans.erase(ans.begin()+ans.length()-1);
    cout<<ans<<endl;
    
    vector<int> ascii;
    for(char c:ans){
        ascii.push_back((int)c);
    }


    sorting(ascii);

    // printing the sorted ascii values
    for(int x:ascii) {
        cout<<x<<" ";
    }
    cout<<endl;

    

}
