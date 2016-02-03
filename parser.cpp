#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std;

int main(){
	ofstream output;
	output.open("test-words.txt");

	ifstream input;
	input.open("train-small.txt");
	
	map<string, int> frq;
	map<string, int>::iterator it;

	string line;
	int total=0;
	if (input.is_open()){
    	while ( getline (input,line) ){
    		//output << line.length()+1<<"\n";
    		char *cstr = new char[line.length()+1];
    		char *token_s;
    		int token_n;
    		strcpy(cstr,line.c_str());
    		//output << cstr<<"\n";
    		token_s = strtok(cstr," ");
    		int i=0;		
    		 while(token_s!=NULL){
    		 	if(i>1){
	    		 	it=frq.find(token_s);
	    		 	if(it==frq.end()){
	    		 		token_n = atoi(strtok(NULL," "));
	    		 		frq.insert(pair<string,int>(token_s,1));
	    		 		output << token_s <<"\n";
	    		 		total++;
	    		 	}
					else{token_n = atoi(strtok(NULL," "));}
	    		}
	    /* 		else if(i==1){
	    			if(token_s[0]== 's'){y << 0 << "\n";}
	    			else {y << 1 << "\n";}
	    		} */
	       		token_s = strtok(NULL," ");
       			i++;
       		}
    	}
    	input.close();
  	}
  	else cout << "Unable to open file \n"; 
	cout << total;

	ofstream x;
	x.open("x_test.txt");
	
	ofstream y;
	y.open("y_test.txt"); 
	
	map<string, int> lfrq;
	map<string, int>::iterator itl;
	
	ifstream inputl;
	inputl.open("test.txt");
	
	string linel;
	if (inputl.is_open()){
    	while ( getline (inputl,linel) ){
    		//output << linel.length()+1<<"\n";
    		char *cstrl = new char[linel.length()+1];
    		char *token_sl;
    		int token_nl;
    		strcpy(cstrl,linel.c_str());
    		//output << cstrl<<"\n";
    		token_sl = strtok(cstrl," ");
    		int i=0;
    		 while(token_sl!=NULL){
    		 	if(i>1){
	    		 	token_nl = atoi(strtok(NULL," "));
	    		 	lfrq.insert(pair<string,int>(token_sl,token_nl));
	    		 	//output << token_sl <<"\n";
	    		 	total++;
	    		}
				else if(i==1){
	    			if(token_sl[0]== 's'){y << -1 << "\n";}
	    			else {y << 1 << "\n";}
	    		}
	       		token_sl = strtok(NULL," ");
       			i++;
       		}
       		it = frq.begin();
       		while(it!=frq.end()){
       			string attr = it->first;
       			itl = lfrq.find(attr);
       			if(itl != lfrq.end()){
       				x << itl->second<<" ";
       			}
       			else{x<< 0<<" ";}
       			it++;
       		}
       		x<<"\n";
       		lfrq.clear();
    	}
  	}
  	else {cout <<"Unable to open file";}

  	/* ofstream aw;
  	aw.open("train-small-out.txt");
  	it = frq.begin();
       	while(it!=frq.end()){
       		string attr = it->first;
       			aw << attr <<" "<< itl->second<<"\n";
       		it++;
       } */

	return 0;
}