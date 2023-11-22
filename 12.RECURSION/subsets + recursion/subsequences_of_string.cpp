#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(string str, int index, string output, vector<string> &ans) {
		if(index >= str.length()){
			ans.push_back(output);
			return ;


		}
		//exclude
		solve(str , index + 1 , output , ans);
		char s = str[index];
		output.push_back(s);
		solve(str , index + 1 , output ,ans);

}

vector<string> subsequences(string str){
	
	vector<string> ans ;
	string output = "";
	int index = 0;
	solve(str , index ,output , ans) ;
	auto it = find(ans.begin() , ans.end() , ""); 
	ans.erase(it);
	return ans ;


	
}

int main(){

    string str = "abc";
    vector<string> ans = subsequences(str);
    cout<<"Printing the subset\n"; //Excluding the null subset
    
    for(string s : ans){
        cout<<s<<endl;
    }

}



