#include<iostream>
#include<string.h>
#include<unistd.h>
#include<cstdlib>
#include<time.h>
#include<fstream>
#include<vector>
using namespace std;
int A=0,user_choice;
ifstream read_from_file;
ofstream fout;
class Player{
	int score_of_player,wickets_taken,runs_conceded,balls_played,wicket_lost;
	float overs_bowled;
	static int skill_level;
	string player_name,type;
	public:
		Player(){
			this->score_of_player=0;
			this->wickets_taken=0;
			this->runs_conceded=0;
			this->balls_played=0;
			this->overs_bowled=0;
			this->wicket_lost=0;
		}
		static int n;
		void set_player_name(string player_name){
			this->player_name=player_name;	
		}
		void set_type(string type){
			this->type=type;	
		}
		string get_player_name(){
			return this->player_name;
		}
		string get_type(){
			return this->type;
		}
		int score(int s){
			score_of_player+=s;	
		}
		void set_score(int s){
			this->score_of_player+=s;
		}
		int get_player_skill(){
			return this->skill_level;
		}
		int get_score() const {
        return this->score_of_player;
	    }
	    void set_wickets_taken(int w=1){
	    	this->wickets_taken+=w;
		}
		int get_wickets_taken(){
	    	return this->wickets_taken;
		}
		void add_runs_conceded(int r){
			this->runs_conceded+=r;
		}
		int get_runs_conceded()const{
			return this->runs_conceded;
		}
		void update_balls_played(int s=1){
			this->balls_played+=s;
		}
		int get_balls_played(){
			return this->balls_played;
		}
		void add_overs_bowled(float s=0.1){
			this->overs_bowled+=s;
			int n=this->overs_bowled*10;
			if(n%10==5){
				this->overs_bowled+=0.5;
			}
		}
		int get_overs_bowled(){
			if(static_cast<int>(this->overs_bowled)==0)
			this->overs_bowled=1;
			return static_cast<int>(this->overs_bowled);
		}
		void set_wicket_lost(){
			this->wicket_lost+=1;
		}
		int get_wicket_lost(){
			return this->wicket_lost;
		}
		void set_balls_played(int n){
			this->balls_played=n;
		}
	    void print_player_info(){
        cout << "Player name: " << this->player_name << endl;
        cout << "Type: " << this->type << endl;
        cout << "Score: " << this->score_of_player << endl;
    	}
    	void reset_score(){
    		this->runs_conceded=0;
    		this->score_of_player=0;
    		this->wickets_taken=0;
    		this->balls_played=0;
    		this->overs_bowled=0;
		}
	Player& operator=(const Player& obj){
		this->balls_played=obj.balls_played;
		this->overs_bowled=obj.overs_bowled;
		this->player_name=obj.player_name;
		this->wicket_lost=obj.wicket_lost;
		this->wickets_taken=obj.wickets_taken;
		this->type=obj.type;
		this->runs_conceded=obj.runs_conceded;
		this->score_of_player=obj.score_of_player;
		return *this;
	}	
};
int Player::n=0;
int Player::skill_level=0;
class Staff{
    string name, role;
public:
    Staff(string name, string role){
        this->name = name;
        this->role = role;
    }
    string get_name(){
        return this->name;
    }
    string get_role(){
        return this->role;
    }
};
class Venue{
    string name, location;
public:
    Venue(string name, string location){
        this->name = name;
        this->location = location;
    }
    string get_name(){
        return this->name;
    }
    string get_location(){
        return this->location;
    }
};
class Umpire{
    string name, country;
public:
    void set_name(string name){
        this->name=name;
    }
    void set_country(string country){
        this->country=country;
    }
    string get_name(){
        return this->name;
    }
    string get_country(){
        return this->country;
    }
};
class BroadcastAgency{
    string name, location;
public:
    BroadcastAgency(string name, string location){
        this->name = name;
        this->location = location;
    }
    string get_name(){
        return this->name;
    }
    string get_location(){
        return this->location;
    }
};
class Team:public Player{
	string name;
	int Team_Wickets_Taken,Team_Wickets_Lost,Team_score,Target;
	public:
	    Team() {
		this->Target=0;
		this->Team_Wickets_Lost=0;
		this->Team_Wickets_Taken=0;
		this->Team_score=0;
	}
	void set_Target(int t){
		this->Target=t;
	}
	vector<Player> players;
	void set_name(string name) {
	this->name = name;
	}
	void reset_Team_score(){
		for(int i=0;i<11;i++){
		this->players[i].reset_score();
	}
	this->Team_score=0;
	this->Team_Wickets_Lost=0;
	this->Team_Wickets_Taken=0;
	this->Target=0;
	}
		
		void Add_Player(Player P){
			players.push_back(P);
		}
		void Remove_Player(Player P){
			// Find the player in the vector and remove it
			for (int i = 0; i < players.size(); i++) {
				if (players[i].get_player_name() == P.get_player_name() && players[i].get_type() == P.get_type()) {
					players.erase(players.begin() + i);
					break;
				}
			}
		}
		string get_name(){
			return this->name;
		}
		int get_Wickets_Lost() const {
	    return this->Team_Wickets_Lost;
		}
		int get_Wickets_Taken() const {
	    return this->Team_Wickets_Taken;
		}
		void add_team_score(Player p){
			this->Team_score+=p.get_score();
		}
		int get_Team_score(){
			return this->Team_score;
		}
		void add_wickets_taken(Player p){
			this->Team_Wickets_Taken+=p.get_wickets_taken();
		}
		void add_wickets_lost(int s=1){
			if(s==0)
			this->Team_Wickets_Lost=0;
			else
			this->Team_Wickets_Lost+=s;
			
		}
		void update_team_score(int s){
			this->Team_score+=s;
		}
		int get_Target(){
			return this->Target;
		}
		void print_batting_scorecard(){
			cout<<"\n 		********Batting Scorecard of "<<this->get_name()<<"********\n";
			cout<<"\n 		 Sr.		Players			Score		   \n\n";
			for(int i=0;i<11;i++){
			cout<<"   		"<<i+1<<". "<<this->players[i].get_player_name()<<"   		 "<<this->players[i].get_score()<<"("<<this->players[i].get_balls_played()<<")"<<endl;
			}
		}
		void print_bowling_scorecard(){
			cout<<"\n 		********Bowling Scorecard of "<<this->get_name()<<"********\n";
			cout<<"\n 		 Sr.		Players			Score Conceded\n\n";
			int a=0;
			for(int i=0;i<11;i++){
				if(this->players[i].get_type()=="Bowler"||this->players[i].get_type()=="bowler"||this->players[i].get_type()=="All Rounder"||this->players[i].get_type()=="All-rounder"||this->players[i].get_type()=="All rounder")
				{
				a++;
				cout<<"   		"<<a<<". " <<this->players[i].get_player_name()<<"   		 "<<this->players[i].get_wickets_taken()<<"-"<<this->players[i].get_runs_conceded()<<"("<<this->players[i].get_overs_bowled()<<")"<<endl;
				}
			}
		}
};
class Match:public Team{
	string Match_type,series,venue;
	int innings;
	bool isfull;
	Team team_1,team_2;
	vector<string> commentary;
    vector<string> highlights;
    vector<string> umpires;
    vector<string> broadcast_agencies;
	public:
		Match(){
		}
	Match(string match_type, string series,string venue,Team team1, Team team2) 
	{
		this->Match_type = match_type;
		this->series = series;
		this->venue=venue;
		this->team_1 = team1;
		this->team_2 = team2;
		this->innings = 0;
        this->isfull = false;
	}

	Team get_team_1() {
		return this->team_1;
	}

	Team get_team_2() {
		return this->team_2;
	}

		int get_innings() {
		return this->innings;
	}
		void add_commentary(string commentary) {
            this->commentary.push_back(commentary);
        }

        vector<string> get_commentary() {
            return this->commentary;
        }

        void add_highlight(string highlight) {
            this->highlights.push_back(highlight);
        }

        vector<string> get_highlights() {
            return this->highlights;
        }

        void add_umpire(string umpire) {
            this->umpires.push_back(umpire);
        }

        vector<string> get_umpires() {
            return this->umpires;
        }

        void add_broadcast_agency(string broadcast_agency) {
            this->broadcast_agencies.push_back(broadcast_agency);
        }

        vector<string> get_broadcast_agencies() {
            return this->broadcast_agencies;
        }

        string get_venue() {
            return this->venue;
        }
        string get_match_type(){
        	return this->Match_type;
		}
		string get_series(){
			return this->series;
		}
		void bowl_by_bowl(Team batting_team, Team bowling_team, char toss_decision, int match_overs,int& win1,int& win2,int match_no,int series,string* str,int Working,string* series_winner);
		void bowl_by_bowl(Team batting_team, Team bowling_team, char toss_decision, int& win1,int& win2,int match_no,int series,string* str,int Working,string* series_winner,string match_type);
		char get_ball_type (Player bowler, Team batting_team, Team bowling_team, int total_runs, int wickets, int target_runs,int Working);
		void Show_Highlights();

};
char Toss(Team team1,Team team2){
//	sleep(1);
//	srand(time(0));
	int n=abs(rand()%2);
	if(n==0)
	{
		cout<<"\n "<<team1.get_name()<<" won the toss.\n";
		return 'H';
	}
	else
	{
		cout<<"\n "<<team2.get_name()<<" won the toss.\n";
		return 'T';
	}
}
int choice(Team t){
	int ch;
	cout<<"\n1. Bat\n2. Bowl\nEnter choice = ";
	cin>>ch;
	if(ch==1){
		cout<<"\n "<<t.get_name()<<" won the toss and elected to Bat.\n";
		return 1;
	}
	if(ch==2){
		cout<<"\n "<<t.get_name()<<" won the toss and elected to Bowl.\n";
		return 0;
	}
}
void get_Commentary(int n,Player bowler,Player batsman){
	if(n==0)
	cout<< "That's the dot ball. Very good ball by "<<bowler.get_player_name()<<endl<<endl;
	else if(n==1)
	cout<< "One run taken by "<<batsman.get_player_name()<<endl<<endl;
	else if(n==2)
	cout<<"Very good running and 2 runs secured by "<<batsman.get_player_name()<<endl<<endl;
	else if(n==3)
	cout<<"Very good running and 3 runs secured by "<<batsman.get_player_name()<<endl<<endl;
	else if(n==4)
	cout<<"4 runs, beautifully played by "<<batsman.get_player_name()<<endl<<endl;
	else if(n==6)
	cout<<"That's the 6, what a shot by "<<batsman.get_player_name()<<endl<<endl;
}
void series_Winner(Team inn1_team,Team inn2_team,int series,string* str,string* series_winner){
		int win1=0,win2=0;
	for(int i=0;i<series;i++){
    		if(series_winner[i]==inn1_team.get_name())
    		win1++;
    		else if(series_winner[i]==inn2_team.get_name())
    		win2++;
		}
//		cout<<"\nResult of series : ";
//	if(win1>win2)                                                                                  
//	cout<<inn1_team.get_name()<<" won the series ";
//	else if(win1<win2)                                 
//	cout<<inn2_team.get_name()<<" won the series ";
//	else                                
//	cout<<"\n\nSeries tied.\n\n\n";     
	cout<<"\nResult of each match : \n";
	for(int i=0;i<series;i++){
		cout<<"\nMatch "<<i+1<<". "<<str[i]<<endl;
	}
}
void Match::bowl_by_bowl(Team batting_team, Team bowling_team, char toss_decision, int match_overs,int& win1,int& win2,int match_no,int series,string* str,int Working,string* series_winner) {
	int inning=0;
	int l=0,bowling_index=0;
	int current_over ;
	int current_ball ;
	int target_runs=0;
	int total_runs   ;
	int wickets      ;
	int num_overs    ;
	Team inn1_team,inn2_team,winning_team,loser_team;
    inn1_team=batting_team;
    inn2_team=bowling_team;
	while(inning<2){
	int Extras=0;
    current_over = 0;
    current_ball = 0;
    int total_balls=0;
    total_runs   = 0;
    wickets      = 0;
    num_overs    = 0;
    Player current_batsman1 = inn1_team.players[l];
    Player current_batsman2 = inn1_team.players[l+1];
	int a=0;
    // Set target for the second innings
    // Bowl ball by ball
    Player temp,striker,non_striker;
    striker=current_batsman1;
    non_striker=current_batsman2;
    Player bowler;
    int n=0,q=0;
    while (num_overs < match_overs && inn1_team.get_Wickets_Lost()!=10) {
    	cout<<"\n"<<striker.get_player_name()<<" is on strike.\n";
	if(current_ball==0)
	{
	    for(int i=0; i<11; i++)
	    {
	        if(inn2_team.players[i].get_type()=="bowler" || inn2_team.players[i].get_type()=="Bowler" || inn2_team.players[i].get_type()=="All Rounder" || inn2_team.players[i].get_type()=="All-rounder")
	        {
	        	if(a==0)
	        	{
	        		n=i;
	        		q=n;
	        		a++;
	        	}
	        	if(q<11){
				
	        	if(inn2_team.players[q].get_type()=="bowler" || inn2_team.players[q].get_type()=="Bowler" || inn2_team.players[q].get_type()=="All Rounder" || inn2_team.players[q].get_type()=="All-rounder")
	        	{
	        	
	        			bowler = inn2_team.players[q];
			            bowling_index=q;
			            q++;
			            break;
				}
			}
				else
					q=n;
	        
	    }
	}
	    cout<<"\nBowler : "<<bowler.get_player_name()<<endl;
	}
        char ball_type = get_ball_type(bowler, inn1_team, inn2_team, total_runs, wickets, target_runs,Working);
		int runs=0;
        // Handle the ball type
        switch (ball_type) {
            case 'W':
                // Batsman is out
                wickets++;
                inn1_team.add_wickets_lost();
                inn1_team.get_balls_played();
                inn2_team.add_wickets_taken(bowler);
                bowler.set_wickets_taken();
                striker.set_wicket_lost();
                striker.update_balls_played();
                bowler.add_overs_bowled();
                if(striker.get_wicket_lost()){
                temp=striker;
            }
                else if(non_striker.get_wicket_lost()){
                temp=non_striker;    
            }
				
                break;
            case 'N':
            	Extras++;
            	inn1_team.update_team_score(1);
            	cout<<"\nThat's the no ball bowled by "<<bowler.get_player_name()<<endl;
                break;
            case 'n':
            	Extras++;
            	inn1_team.update_team_score(1);
            	cout<<"\nThat's the no ball bowled by "<<bowler.get_player_name()<<endl;
                break;
            case 'I':
            	Extras++;
            	inn1_team.update_team_score(1);
            	cout<<"\nThat's the wide ball bowled by "<<bowler.get_player_name()<<endl;
                break;
            case 'i':
            	Extras++;
            	inn1_team.update_team_score(1);
            	cout<<"\nThat's the wide ball bowled by "<<bowler.get_player_name()<<endl;
                break;
            default:
                // Runs scored
                runs = ball_type -'0';
                striker.score(runs);
                inn1_team.update_team_score(runs);
                inn1_team.update_balls_played();
                bowler.add_runs_conceded(runs);
                bowler.add_overs_bowled();
                striker.update_balls_played();
                total_runs += runs;
                //cout << "Runs scored: " << inn1_team.get_Team_score() << endl;
                // Check if the batsmen crossed, and switch ends if they did
                if(current_batsman1.get_player_name()==striker.get_player_name() && current_batsman1.get_player_skill()==striker.get_player_skill())
				{
					current_batsman2=non_striker;
					current_batsman1=striker;
				}
				else
				{
					current_batsman1=non_striker;
					current_batsman2=striker;
				}
                break;
        }
        if(wickets!=inn1_team.players.size() - 1){
		for(int i=0;i<11;i++){
			if(inn1_team.players[i].get_player_name()==temp.get_player_name())
			{
				inn1_team.players[i]=temp;
			}
			if(inn1_team.players[i].get_player_name()==current_batsman1.get_player_name())
			inn1_team.players[i]=current_batsman1;
			if(inn1_team.players[i].get_player_name()==current_batsman2.get_player_name())
			inn1_team.players[i]=current_batsman2;
		}
    }
        inn2_team.players[bowling_index]=bowler;
		current_ball++;
		total_balls++;
		if(ball_type=='W'){
              	if (striker.get_wicket_lost() && wickets!=inn1_team.players.size() - 1) 
				{
//                    // One of the batsmen is out, and we need to switch ends
					//current_batsman1 = inn1_team.players[wickets];
                    
						if(striker.get_player_name()==current_batsman2.get_player_name()&&striker.get_player_skill()==current_batsman2.get_player_skill()){
							current_batsman2 = inn1_team.players[wickets + 1];
							striker=current_batsman2;
							non_striker=current_batsman1;
						}
						else{
							if(striker.get_player_name()==current_batsman1.get_player_name()&&striker.get_player_skill()==current_batsman1.get_player_skill()){
								current_batsman1 = inn1_team.players[wickets + 1];
								striker=current_batsman1;
								non_striker=current_batsman2;
							}
						}
                    
                }
	                else if (non_striker.get_wicket_lost() && wickets!=inn1_team.players.size() - 1) 
					{
//                    // One of the batsmen is out, and we need to keep the same batsman on strike
						//current_batsman1 = inn1_team.players[wickets];
                    
						if(non_striker.get_player_name()==current_batsman2.get_player_name()&&non_striker.get_player_skill()==current_batsman2.get_player_skill()){
							current_batsman2 = inn1_team.players[wickets + 1];
							non_striker=current_batsman2;
							striker=current_batsman1;
						}
						else{
							if(non_striker.get_player_name()==current_batsman1.get_player_name()&&non_striker.get_player_skill()==current_batsman1.get_player_skill()){
							current_batsman1 = inn1_team.players[wickets + 1];
							non_striker=current_batsman1;
							striker=current_batsman2;
							}
						}                    
               		}
		}
        // Print the scorecard for the current batsmen
        //if (runs % 2 != 1)
        if(current_ball==6){
		if(temp.get_wicket_lost())
		{
			cout<<num_overs+1<<"."<<"0==>"<<bowler.get_player_name()<<" to "<<temp.get_player_name()<<" : "<<temp.get_player_name()<<" --> "<<temp.get_score()<<"("<<temp.get_balls_played()<<")\n";
			for(int i=0;i<players.size();i++){
			if(players[i].get_player_name()==temp.get_player_name()){
			inn1_team.players[i]=temp;
		//	players[i].set_wicket_lost();
		}
		}
		}
		else
		{
        cout<<num_overs+1<<"."<<"0==>"<<bowler.get_player_name()<<" to "<<striker.get_player_name()<<" : "<<striker.get_player_name()<<" --> "<<striker.get_score()<<"("<<striker.get_balls_played()<<")\n";
		for(int i=0;i<players.size();i++){
			if(players[i].get_player_name()==striker.get_player_name())
			inn1_team.players[i]=striker;
		}
		}
	}
		else{
		if(temp.get_wicket_lost())
		{
			cout<<num_overs<<"."<<current_ball<<"==>"<<bowler.get_player_name()<<" to "<<temp.get_player_name()<<" : "<<temp.get_player_name()<<" --> "<<temp.get_score()<<"("<<temp.get_balls_played()<<")\n";
			
			for(int i=0;i<players.size();i++){
			if(inn1_team.players[i].get_player_name()==temp.get_player_name()){
			inn1_team.players[i].set_balls_played(temp.get_balls_played());
			inn1_team.players[i].set_wicket_lost();
		}
		}
		}
		else	
        cout<<num_overs<<"."<<current_ball<<"==>"<<bowler.get_player_name()<<" to "<<striker.get_player_name()<<" : "<<striker.get_player_name()<<" --> "<<striker.get_score()<<"("<<striker.get_balls_played()<<")\n";
    	for(int i=0;i<players.size();i++){
			if(inn1_team.players[i].get_player_name()==striker.get_player_name())
			inn1_team.players[i].set_balls_played(striker.get_balls_played());
		}
		}
		if(ball_type=='W'){
        cout<<"\nWhat a great wicket taken by "<<bowler.get_player_name()<<" and here "<<temp.get_player_name()<<" is Out.\n";
        temp=striker;
    	}
    	if(ball_type=='W'){
				if(wickets==inn1_team.players.size() - 1){
                	cout<<"\nAll out!";
				}
			}
    	if(ball_type!='W'&&ball_type!='N')
		get_Commentary(runs,bowler,striker);
		if (runs % 2 == 1) {
                	
                    if(current_batsman1.get_player_name()==striker.get_player_name() && current_batsman1.get_player_skill()==striker.get_player_skill())
					{
						striker=current_batsman2;
						non_striker=current_batsman1;
					}
					else{
						striker=current_batsman1;
						non_striker=current_batsman2;
					}
                }
		if (current_ball % 6 == 0) {
        current_ball=0;
       // bowler.get_balls_bowled()
	    num_overs++;
	    inn2_team.players[bowling_index]=bowler;
	    //cout << "End of over " << num_overs << endl;
	    cout<<bowler.get_player_name()<<"  ( "<<bowler.get_wickets_taken()<<"-"<<bowler.get_runs_conceded()<<" ) \n";
	    cout<<"Score of "<<inn1_team.get_name()<<" at the End of over "<<num_overs<<" is " <<inn1_team.get_Team_score()<<" with "<<inn1_team.get_Wickets_Lost()<<" loss of wickets."<<endl;
	    float avg=static_cast <float>(total_runs)/num_overs;
	    cout<<"Average = "<<avg<<endl;
	    if(inning==0){
	    	int Projected_Score=avg*match_overs;
	    	cout<<"Projected Score = "<<Projected_Score<<endl<<endl<<endl;
		}
	    if(inning==1){
	    float remaining_overs=match_overs-num_overs;
		cout<<inn1_team.get_name()<<" need "<<target_runs-total_runs<<" from "<<(match_overs*6) - ((num_overs*6))<<" balls at the rate of "<<(target_runs-total_runs)/remaining_overs<<" runs per over.\n\n\n";
		}
		// Swap the batsmen at the end of the over
		if(current_batsman1.get_player_name()==striker.get_player_name() && current_batsman1.get_player_skill()==striker.get_player_skill())
		{
			striker=current_batsman2;
			non_striker=current_batsman1;
		}
		else{
			striker=current_batsman1;
			non_striker=current_batsman2;
		}
		}

if ((wickets == inn1_team.players.size() - 1 || num_overs == match_overs)&& inning==0) {
    // Innings is over
    cout << "1st Innings over!" << endl;
    cout << "Total runs: " << total_runs << "/" << wickets << endl;
    target_runs = total_runs + 1;
    inn1_team.set_Target(target_runs);
	batting_team=inn1_team;
	bowling_team=inn2_team;
	inning++;
	// Set target for the second innings
	cout<<"\n"<<bowling_team.get_name()<<" need "<<batting_team.get_Target()<<" runs to win at the rate of "<<batting_team.get_Target()/static_cast<float>(match_overs)<<" runs per over.\n";
	batting_team.print_batting_scorecard();  
	cout<<"\n\n\t Extras = "<<Extras<<"					Total score = "<<total_runs<<"/"<<wickets<<endl;
    bowling_team.print_bowling_scorecard();
    cout<<"\n\n\aNow here is the break and 2nd innings will start in few moments.\n";
    system("pause");
//    for (int i = 0; i < inn1_team.players.size(); i++) {
//    inn1_team.players[i].reset_score();
//    inn2_team.players[i].reset_score();
//	}
	inn1_team=bowling_team;
	inn2_team=batting_team;
	break;
}

else if((wickets == inn2_team.players.size() - 1 || num_overs == match_overs || total_runs>=target_runs)&& inning==1){
	inning++;
	cout << "2nd Innings over!" << endl;
//		batting_team=inn1_team;
//		bowling_team=inn2_team;
		inn1_team.print_batting_scorecard();
		cout<<"\n\n\t Extras = "<<Extras<<"					Total score = "<<total_runs<<"/"<<wickets<<endl;
    	inn2_team.print_bowling_scorecard();
	break;
}
}
}

	if(total_runs >= target_runs)// The batting team won
	{
		cout << inn1_team.get_name() << " won the match by " << 10-inn1_team.get_Wickets_Lost() << " wickets." << endl;
		str[match_no] = inn1_team.get_name() + " won the match. " ;//+ to_string(10 - inn1_team.get_Wickets_Lost()) + " wickets.";
		winning_team=inn1_team;
		series_winner[match_no]=winning_team.get_name();
		loser_team=inn2_team;
		win1++;
	}
    else if (total_runs < target_runs-1) {
        // The batting team lost
        cout << inn1_team.get_name() << " lost the match by " << target_runs - total_runs << " runs." << endl;
        //str[match_no]=inn1_team.get_name() << " lost the match by " << target_runs - total_runs << " runs.";
        str[match_no] = inn2_team.get_name() + " won the match."; //+ to_string(target_runs - total_runs) + " wickets.";
		winning_team=inn2_team;
		series_winner[match_no]=winning_team.get_name();
        loser_team=inn1_team;
        win2++;
    } 
	else {
        // The match was a tie
        cout << "The match was a tie!" << endl;
        str[match_no]="Match Tied.";
        series_winner[match_no]="NULL";
    }
//    if(win1>win2 && match_no!=series-1)
//    cout<<"\n\n"<<inn1_team.get_name()<<" lead the series by "<<win1<<"-"<<win2<<endl<<endl<<endl;
//    else if(win1<win2 && match_no!=series-1)
//    cout<<"\n\n"<<inn2_team.get_name()<<" lead the series by "<<win2<<"-"<<win1<<endl<<endl<<endl;
//	else if(win1==win2 && match_no!=series-1)
//	cout<<"\n\nSeries level.\n\n\n";
if(user_choice==1){
	if(match_no!=series-1){
		cout<<"\nNow starting Match # "<<match_no+2<<endl;//". Press any key to continue.";
		system("pause");
	}
	if(match_no==series-1){
		series_Winner(winning_team,loser_team,series,str,series_winner);
	}
}
}
char Match::get_ball_type (Player bowler, Team batting_team, Team bowling_team, int total_runs, int wickets, int target_runs,int Working) {
   if(Working==2)
   sleep(0); 
   //srand(time(1));
   char ch;
if(Working==1){
	if(user_choice==1){
	cout<<"\nEnter the outcome of ball = ";
	while(1){
	cin>>ch;
	if((ch!='5' && ch<'7' && ch>='0')||ch=='W'||ch=='n'||ch=='N'||ch=='I'||ch=='i'){
	fout<<ch<<"	 ";
	return ch;
}
	else
	cout<<"\nInvalid score. Enter again = ";
	}
}
if(user_choice==2){
	read_from_file>>ch;
	return ch;
}
}
else if(Working==2){
	int n=rand()%7;
	if(n==0)
	{
	
		if(A==0 || A%5!=0){
			A++;
			ch='0';
		}
		else
		{
			ch='W';
		
		}
	}
	else if(n==1 || n==5){
	ch='1';
	
}
	else if(n==2){
	ch='2';
	
}
	else if(n==4){
	
	ch='4';

}
	else if(n==3){
	ch='3';
	
}
	else if(n==6){
	
	ch='6';
	
}
fout<<ch<<"  ";
return ch;
}
}


void Match::bowl_by_bowl(Team batting_team, Team bowling_team, char toss_decision,int& win1,int& win2,int match_no,int series,string* str,int Working,string* series_winner,string match_type){
	int inning=0;
	int inn=0;
	int l=0,bowling_index=0;
	int current_over ;
	int current_ball ;
	int target_runs=0;
	int total_runs   ;
	int wickets      ;
	int num_overs    ;
	Team inn1_team,inn2_team,winning_team,loser_team;
    inn1_team=batting_team;
    inn2_team=bowling_team;
    int trail=0,lead=0;
    int target_with_lead=0;
    int t=0,mp=0;
	while(inning < 4){
	int Extras=0;
    current_over = 0;
    current_ball = 0;
    int total_balls=0;
    wickets      = 0;
    num_overs    = 0;
    Player current_batsman1 = inn1_team.players[l];
    Player current_batsman2 = inn1_team.players[l+1];
	int a=0;
    // Set target for the second innings
    // Bowl ball by ball
    Player temp,striker,non_striker;
    striker=current_batsman1;
    non_striker=current_batsman2;
    Player bowler;
    int n=0,q=0;
    inn1_team.reset_Team_score();
    inn2_team.reset_Team_score();
    inn1_team.add_wickets_lost(0);
//    cout<<"hello";
    while (inn1_team.get_Wickets_Lost()!=10) {
    	cout<<"\n"<<striker.get_player_name()<<" is on strike.\n";
	if(current_ball==0)
	{
	    for(int i=0; i<11; i++)
	    {
	        if(inn2_team.players[i].get_type()=="bowler" || inn2_team.players[i].get_type()=="Bowler" || inn2_team.players[i].get_type()=="All Rounder" || inn2_team.players[i].get_type()=="All-rounder")
	        {
	        	if(a==0)
	        	{
	        		n=i;
	        		q=n;
	        		a++;
	        	}
	        	if(q<11){
				
	        	if(inn2_team.players[q].get_type()=="bowler" || inn2_team.players[q].get_type()=="Bowler" || inn2_team.players[q].get_type()=="All Rounder" || inn2_team.players[q].get_type()=="All-rounder")
	        	{
	        	
	        			bowler = inn2_team.players[q];
			            bowling_index=q;
			            q++;
			            break;
				}
			}
				else
					q=n;
	        
	    }
	}
	    cout<<"\nBowler : "<<bowler.get_player_name()<<endl;
	}
        char ball_type = get_ball_type(bowler, inn1_team, inn2_team, total_runs, wickets, target_runs,Working);
		int runs=0;
        // Handle the ball type
        switch (ball_type) {
            case 'W' :
                // Batsman is out
                wickets++;
                inn1_team.add_wickets_lost();
                inn1_team.get_balls_played();
                inn2_team.add_wickets_taken(bowler);
                bowler.set_wickets_taken();
                striker.set_wicket_lost();
                striker.update_balls_played();
                bowler.add_overs_bowled();
                if(striker.get_wicket_lost()){
                temp=striker;
            }
                else if(non_striker.get_wicket_lost()){
                temp=non_striker;    
            }
				
                break;
            case 'N':
            	Extras++;
            	inn1_team.update_team_score(1);
            	cout<<"\nThat's the no ball bowled by "<<bowler.get_player_name()<<endl;
                break;
            case 'n':
            	Extras++;
            	inn1_team.update_team_score(1);
            	cout<<"\nThat's the no ball bowled by "<<bowler.get_player_name()<<endl;
                break;
            case 'I':
            	Extras++;
            	inn1_team.update_team_score(1);
            	cout<<"\nThat's the wide ball bowled by "<<bowler.get_player_name()<<endl;
                break;
            case 'i':
            	Extras++;
            	inn1_team.update_team_score(1);
            	cout<<"\nThat's the wide ball bowled by "<<bowler.get_player_name()<<endl;
                break;
            default:
                // Runs scored
                runs = ball_type -'0';
                striker.score(runs);
                inn1_team.update_team_score(runs);
                inn1_team.update_balls_played();
                bowler.add_runs_conceded(runs);
                bowler.add_overs_bowled();
                striker.update_balls_played();
                total_runs += runs;
                //cout << "Runs scored: " << inn1_team.get_Team_score() << endl;
                // Check if the batsmen crossed, and switch ends if they did
                if(current_batsman1.get_player_name()==striker.get_player_name() && current_batsman1.get_player_skill()==striker.get_player_skill())
				{
					current_batsman2=non_striker;
					current_batsman1=striker;
				}
				else
				{
					current_batsman1=non_striker;
					current_batsman2=striker;
				}
                break;
        }
        if(wickets!=inn1_team.players.size() - 1){
		for(int i=0;i<11;i++){
			if(inn1_team.players[i].get_player_name()==temp.get_player_name())
			{
				inn1_team.players[i]=temp;
			}
			if(inn1_team.players[i].get_player_name()==current_batsman1.get_player_name())
			inn1_team.players[i]=current_batsman1;
			if(inn1_team.players[i].get_player_name()==current_batsman2.get_player_name())
			inn1_team.players[i]=current_batsman2;
		}
    }
        inn2_team.players[bowling_index]=bowler;
		current_ball++;
		total_balls++;
		if(ball_type=='W'){
			if(wickets==inn1_team.players.size() - 1){
                	cout<<"\nAll out!";
			}
              	else if (striker.get_wicket_lost()) 
				{
//                    // One of the batsmen is out, and we need to switch ends
                    
						if(striker.get_player_name()==current_batsman2.get_player_name()&&striker.get_player_skill()==current_batsman2.get_player_skill()){
							current_batsman2 = inn1_team.players[wickets + 1];
							striker=current_batsman2;
							non_striker=current_batsman1;
						}
						else{
							if(striker.get_player_name()==current_batsman1.get_player_name()&&striker.get_player_skill()==current_batsman1.get_player_skill()){
								current_batsman1 = inn1_team.players[wickets + 1];
								striker=current_batsman1;
								non_striker=current_batsman2;
							}
						}
                    
                }
	                else if (non_striker.get_wicket_lost() ) 
					{
//                    // One of the batsmen is out, and we need to keep the same batsman on strike
						//current_batsman1 = inn1_team.players[wickets];
                    
						if(non_striker.get_player_name()==current_batsman2.get_player_name()&&non_striker.get_player_skill()==current_batsman2.get_player_skill()){
							current_batsman2 = inn1_team.players[wickets + 1];
							non_striker=current_batsman2;
							striker=current_batsman1;
						}
						else{
							if(non_striker.get_player_name()==current_batsman1.get_player_name()&&non_striker.get_player_skill()==current_batsman1.get_player_skill()){
							current_batsman1 = inn1_team.players[wickets + 1];
							non_striker=current_batsman1;
							striker=current_batsman2;
							}
						}                    
               		}
		}
        // Print the scorecard for the current batsmen
        //if (runs % 2 != 1)
        if(current_ball==6){
		if(temp.get_wicket_lost())
		{
			cout<<num_overs+1<<"."<<"0==>"<<bowler.get_player_name()<<" to "<<temp.get_player_name()<<" : "<<temp.get_player_name()<<" --> "<<temp.get_score()<<"("<<temp.get_balls_played()<<")\n";
			for(int i=0;i<players.size();i++){
			if(players[i].get_player_name()==temp.get_player_name()){
			players[i]=temp;
		//	players[i].set_wicket_lost();
		}
		}
		}
		else
		{
        cout<<num_overs+1<<"."<<"0==>"<<bowler.get_player_name()<<" to "<<striker.get_player_name()<<" : "<<striker.get_player_name()<<" --> "<<striker.get_score()<<"("<<striker.get_balls_played()<<")\n";
		for(int i=0;i<players.size();i++){
			if(players[i].get_player_name()==striker.get_player_name())
			players[i]=striker;
		}
		}
	}
		else{
		if(temp.get_wicket_lost())
		{
			cout<<num_overs<<"."<<current_ball<<"==>"<<bowler.get_player_name()<<" to "<<temp.get_player_name()<<" : "<<temp.get_player_name()<<" --> "<<temp.get_score()<<"("<<temp.get_balls_played()<<")\n";
			
			for(int i=0;i<players.size();i++){
			if(players[i].get_player_name()==temp.get_player_name()){
			players[i].set_balls_played(temp.get_balls_played());
			players[i].set_wicket_lost();
		}
		}
		}
		else	
        cout<<num_overs<<"."<<current_ball<<"==>"<<bowler.get_player_name()<<" to "<<striker.get_player_name()<<" : "<<striker.get_player_name()<<" --> "<<striker.get_score()<<"("<<striker.get_balls_played()<<")\n";
    	for(int i=0;i<players.size();i++){
			if(players[i].get_player_name()==striker.get_player_name())
			players[i].set_balls_played(striker.get_balls_played());
		}
		}
		if(ball_type=='W'){
        cout<<"\nWhat a great wicket taken by "<<bowler.get_player_name()<<" and here "<<temp.get_player_name()<<" is Out.\n";
        temp=striker;
    	}
    	if(ball_type!='W'&&ball_type!='N')
		get_Commentary(runs,bowler,striker);
		if (runs % 2 == 1) {
                	
                    if(current_batsman1.get_player_name()==striker.get_player_name() && current_batsman1.get_player_skill()==striker.get_player_skill())
					{
						striker=current_batsman2;
						non_striker=current_batsman1;
					}
					else{
						striker=current_batsman1;
						non_striker=current_batsman2;
					}
                }
		if (current_ball % 6 == 0) {
        current_ball=0;
       // bowler.get_balls_bowled()
	    num_overs++;
	    inn2_team.players[bowling_index]=bowler;
	    //cout << "End of over " << num_overs << endl;
	    cout<<bowler.get_player_name()<<"  ( "<<bowler.get_wickets_taken()<<"-"<<bowler.get_runs_conceded()<<" ) \n";
	    cout<<"Score of "<<inn1_team.get_name()<<" at the End of over "<<num_overs<<" is " <<inn1_team.get_Team_score()<<" with "<<inn1_team.get_Wickets_Lost()<<" loss of wickets."<<endl;
	    float avg=static_cast <float>(total_runs)/num_overs;
	    cout<<"Average = "<<avg<<endl;
	    if(inning!=3 && total_runs<target_runs){
			cout<<inn1_team.get_name()<<" trail by "<<target_runs-total_runs<<" runs.\n";
		}
		if(inning==3 && total_runs<target_runs){
			cout<<inn1_team.get_name()<<" need "<<target_runs-total_runs<<" runs to win.\n";
		}
		// Swap the batsmen at the end of the over
		if(current_batsman1.get_player_name()==striker.get_player_name() && current_batsman1.get_player_skill()==striker.get_player_skill())
		{
			striker=current_batsman2;
			non_striker=current_batsman1;
		}
		else{
			striker=current_batsman1;
			non_striker=current_batsman2;
		}
		}
if (wickets == inn1_team.players.size() - 1 && inning==0 ) {
    // Innings is over
    cout << "Total runs: " << total_runs << "/" << wickets << endl;
    target_runs = total_runs;
    inn1_team.set_Target(target_runs);
	batting_team=inn1_team;
	bowling_team=inn2_team;
	inning++;
	// Set trail for the second innings
	batting_team.print_batting_scorecard();  
	cout<<"\n\n\t Extras = "<<Extras<<"					Total score = "<<total_runs<<"/"<<wickets<<endl;
    bowling_team.print_bowling_scorecard();
    total_runs=0;
    cout<<"\n"<<bowling_team.get_name()<<" trail by "<<batting_team.get_Target()<<" runs.\n";
    cout<<"\n\n\aNow here is the break and match will resume in in few moments.\n";
    system("pause");
	inn1_team=bowling_team;
	inn2_team=batting_team;
	break;
}
else if(wickets == inn2_team.players.size() - 1 && inning==1 ){
	inning++;
//	inn++;
		cout << "1st Innings over!" << endl;
		batting_team=inn2_team;
		bowling_team=inn1_team;
		inn1_team.print_batting_scorecard();
		cout<<"\n\n\t Extras = "<<Extras<<"					Total score = "<<total_runs<<"/"<<wickets<<endl;
    	inn2_team.print_bowling_scorecard();
    	if(total_runs > target_runs)// The batting team won
		{
			trail=total_runs-target_runs;
			cout << inn2_team.get_name() << " trail by " << trail<< " runs." << endl;
			target_runs=trail;
			t++;
		}
		else{
			lead=target_runs-total_runs;
			cout << inn2_team.get_name() << " lead by " <<lead << " runs." << endl;
			target_with_lead=lead;
			mp++;
		}
		total_runs=0;
		cout<<"\n\n\aNow here is the break and 2nd innings will start in few moments.\n";
    	system("pause");
    	inn2_team=bowling_team;
    	inn1_team=batting_team;
		break;
}
	else if(wickets == inn1_team.players.size()-1 && inning==2){
		//cout<<"hello";
		batting_team=inn1_team;
		bowling_team=inn2_team;
		inning++;
		inn1_team.print_batting_scorecard();
		cout<<"\n\n\t Extras = "<<Extras<<"					Total score = "<<total_runs<<"/"<<wickets<<endl;
    	inn2_team.print_bowling_scorecard();
	if(t==1){
		if(total_runs>trail)
		target_runs=total_runs-trail;
		else
		{
		cout<<"\n"<<inn2_team.get_name()<<" won the match by "<<trail-total_runs<<" runs.\n";
		exit(1);
		}
	}
	else if(mp==1){
		target_runs=total_runs+target_with_lead;
	}
	total_runs=0;
	cout<<"\n"<<bowling_team.get_name()<<" need "<<target_runs<<" to win.\n";
	inn1_team=bowling_team;
	inn2_team=batting_team;
	cout<<"\n\n\aNow here is the break and last innings will start in few moments.\n";
    system("pause");
	break;
}
	else if((wickets == 10 || total_runs>=target_runs) && inning==3 ){
		inning++;
		cout<<"\n2nd innings over.";
		batting_team=inn2_team;
		bowling_team=inn1_team;
		inn1_team.print_batting_scorecard();
		cout<<"\n\n\t Extras = "<<Extras<<"					Total score = "<<total_runs<<"/"<<wickets<<endl;
    	inn2_team.print_bowling_scorecard();
    	if(total_runs==target_runs-1){
			cout<<"\nMatch Tied.\n";
		}
		if(total_runs<target_runs){
			cout<<"\n"<<batting_team.get_name()<<" won the match by "<<target_runs-total_runs-1<<" runs.\n";
			str[match_no] = batting_team.get_name() + " won the match.";
		}
		else if(total_runs>=target_runs){
			cout<<"\n"<<bowling_team.get_name()<<" won the match by "<<10-wickets<<" wickets.\n";
			str[match_no] = bowling_team.get_name() + " won the match.";
		}
		system("pause");
		break;
	}
}
}
if(user_choice==1){
	if(match_no!=series-1){
		cout<<"\nNow starting Match # "<<match_no+2<<endl;//". Press any key to continue.";
		system("pause");
	}
	if(match_no==series-1){
		series_Winner(winning_team,loser_team,series,str,series_winner);
	}
}
}

void select_teams(){
	cout<<"\n 1. Pakistan\n 2. India\n 3. Australia\n 4. England\n 5. Afghanistan\n 6. South Africa\n";
}

//Main() starts here____________________________________________________________________________________________________________________________
 
 
int main() {
	char play_again;
	int format;
	ifstream fin;
	int win1=0,win2=0;
	string* series_winner;
	string* str;
	do{
	int ch;
	string s;
	int match_overs;
	string match_type;
	Team team1,team2,t,tbowl,tbat;
	Player *players_bat;
	Player *players_bowl;
	cout<<"\n 1. Enter data of new match.\n 2. See replay of previous match\n";
	cin>>user_choice;
	if(user_choice==1){
	fout.open("Save and Replay.txt");
	cout<<"\n \n 1. T20\n 2. ODI\n 3. Test\n Select format : ";
	cin>>ch;
	fout<<ch<<endl;
    if(ch==1){
    	match_overs=20;
    	match_type="T20";
	}
	if(ch==2){
		match_overs=50;
    	match_type="ODI";
	}
	if(ch==3){
		//match_overs=300;
    	match_type="Test";
	}
	int select_team=0;
		
		do{
		cout<<"\nTeams List\n";
		select_teams();
		cout<<"\nSelect Team 1 = ";
		cin>>select_team;
		if(select_team==1)
			team1.set_name("Pakistan");
		else if(select_team==2)
			team1.set_name("India");
		else if(select_team==3)
			team1.set_name("Australia");
		else if(select_team==4)
			team1.set_name("England");
		else if(select_team==5)
			team1.set_name("Afghanistan");
		else if(select_team==6)
			team1.set_name("South Africa");	
		else
			cout<<"\n\aInvalid choice.Enter again.\n";
		}while(select_team<1 || select_team>6);
		fout<<team1.get_name()<<endl;
		do{
			do{
		cout<<"\nTeams List\n";
		select_teams();
		cout<<"\nSelect Team 2 = ";
		cin>>select_team;
		if(select_team==1)
			team2.set_name("Pakistan");
		else if(select_team==2)
			team2.set_name("India");
		else if(select_team==3)
			team2.set_name("Australia");
		else if(select_team==4)
			team2.set_name("England");
		else if(select_team==5)
			team2.set_name("Afghanistan");
		else if(select_team==6)
			team2.set_name("South Africa");	
		else
			cout<<"\n\aInvalid choice.Enter again.\n";
		}while(select_team<1 || select_team>6);
		if(team1.get_name()==team2.get_name()){
			cout<<"\n\aError! Names of both teams cannot be same.Enter again.";
		}
		}while(team1.get_name()==team2.get_name());
}
	fout<<team2.get_name()<<endl;
	if(user_choice==2){
		read_from_file.open("Save and Replay.txt");
		read_from_file>>format;
		if(format==1)
		{
			match_overs=20;
			match_type="T20";
		}
		if(format==2){
		match_overs=50;
		match_type="T20";
	}
		if(format==3)
		match_type="Test";
		getline(read_from_file,s);
		team1.set_name(s);
		getline(read_from_file,s);
		team2.set_name(s);
		cout<<"\nTeam 1 : "<<team1.get_name()<<endl;
		cout<<"\nTeam 2 : "<<team2.get_name()<<endl;
	}
    // Create some players and add them to the teams
    Player *players1=new Player[11];
    t.set_name(team1.get_name());
    //string s;
    if(t.get_name()=="India"){
    	fin.open("India.txt");
    }
    if(t.get_name()=="Australia"){
    	fin.open("Australia.txt");
    }
    if(t.get_name()=="England"){
    	fin.open("England.txt");
    }
    if(t.get_name()=="Afghanistan"){
    	fin.open("Afghanistan.txt");
    }
    if(t.get_name()=="Pakistan"){
    	fin.open("Pakistan.txt");
    }
    if(t.get_name()=="South Africa"){
    	fin.open("SA.txt");
    }
    	for(int i=0;i<11;i++){
    	if(fin.is_open()){
    		getline(fin,s);
    		players1[i].set_player_name(s);
    		getline(fin,s);
    		players1[i].set_type(s);
    		team1.Add_Player(players1[i]);
		}
	}
	fin.close();
	Player *players2=new Player[11];
    t.set_name(team2.get_name());
    if(t.get_name()=="India"){
    	fin.open("India.txt");
    }
    if(t.get_name()=="Australia"){
    	fin.open("Australia.txt");
    }
    if(t.get_name()=="England"){
    	fin.open("England.txt");
    }
    if(t.get_name()=="Afghanistan"){
    	fin.open("Afghanistan.txt");
    }
    if(t.get_name()=="Pakistan"){
    	fin.open("Pakistan.txt");
    }
    if(t.get_name()=="South Africa"){
    	fin.open("SA.txt");
    }
    	for(int i=0;i<11;i++){
    	if(fin.is_open()){
    		getline(fin,s);
    		players2[i].set_player_name(s);
    		getline(fin,s);
    		players2[i].set_type(s);
    		team2.Add_Player(players2[i]);
		}
	}
    // Create a match with the two teams
    Match match(match_type, "Series 1", "Lahore", team1, team2);
	
	match.add_broadcast_agency("Ford");
	match.add_broadcast_agency("Pepsi");
	match.add_broadcast_agency("Honda");
	match.add_broadcast_agency("Ceat Tyres");
    // Get match details
    if(user_choice==1)
    {
    int series;
    cout<<"\nEnter the no. of matches in the series = ";
    cin>>series;
    str=new string[series];
    cout<<endl<<endl;
    int i=0;
    while(i<series)
    {
    cout << "Match details:" << endl;
    cout << "Match type: " << match.get_match_type() << endl;
    cout << "Series: " << match.get_series() << endl;
    cout << "Venue: " << match.get_venue() << endl;
    cout << "Team 1: " <<team1.get_name() << endl;
    cout << "Team 2: " << team2.get_name() << endl;
    // Get commentary, highlights, umpires, and broadcast agencies
    vector<string> commentary = match.get_commentary();
    vector<string> highlights = match.get_highlights();
    vector<string> umpires = match.get_umpires();
    vector<string> broadcast_agencies = match.get_broadcast_agencies();
    cout<<"\n 		********Players of "<<team1.get_name()<<"********\n";
	for(int o=0;o<11;o++)
	{
		cout<<"		"<<o+1<<". "<<players1[o].get_player_name()<<" ( "<<players1[o].get_type()<<" )		   \n";
	}
	cout<<"\n 		********Players of "<<team2.get_name()<<"********\n";
	for(int o=0;o<11;o++)
	{
		cout<<"		"<<o+1<<". "<<players2[o].get_player_name()<<" ( "<<players2[o].get_type()<<" )\n";
	}
	Umpire *u=new Umpire[3];
	u[0].set_name("Aleem Dar");
	u[0].set_country("Pakistan");
	u[1].set_name("Marais Erasmus");
	u[1].set_country("South Africa");
	u[2].set_name("Kumar Dharmasena");
	u[2].set_country("Sri Lanka");
    cout << "\n\n Field Umpires :" << endl<<" ";
    cout<<u[0].get_name()<<" from "<<u[0].get_country()<<endl<<" ";
    cout<<u[1].get_name()<<" from "<<u[1].get_country()<<endl;
    cout<<"\n Third umpire :\n ";
    cout<<u[2].get_name()<<" from "<<u[2].get_country()<<endl;
//Broadcast Agencies
    cout << "\nBroadcast agencies:" << endl;
    for (int o = 0; o < broadcast_agencies.size(); o++) {
        cout << o+1<<". " << broadcast_agencies[o] << endl;
    }
    cout<<"\n Heads(H) is for "<<team1.get_name()<<" and Tails(T) is for "<<team2.get_name()<<endl;
    char toss=Toss(team1,team2);
    int flag;
    if(toss=='T')
    {
    flag=choice(team2);
  //  t=team2;
    	if(flag==1)
    	{
			tbowl=team1;
			tbat=team2;
			players_bat=players2;
			players_bowl=players1;
		}
		else
		{
			tbowl=team2;
			tbat=team1;
			players_bat=players1;
			players_bowl=players2;
		}		
	}
    if(toss=='H'){
    flag=choice(team1);
  //  t=team1;
  		if(flag==1)
    	{
    		tbowl=team2;
			tbat=team1;
			players_bat=players1;
			players_bowl=players2;
		}
		else
		{
			tbowl=team1;
			tbat=team2;
			players_bat=players2;
			players_bowl=players1;
		}	
	}
	int Working;
	cout<<"\n1. Enter score bowl by bowl manually.\n2. Enter automatic score.\n";
	cout<<"\nEnter your choice = ";
	cin>>Working;
	series_winner=new string[series];
	//Bowl_by_Bowl(tbat,tbowl,players_bat,players_bowl);
	if(match.get_match_type()=="T20"||match.get_match_type()=="ODI")
	match.bowl_by_bowl(tbat, tbowl, toss,match_overs,win1,win2,i,series,str,Working,series_winner);		//For T20 & ODI
	else if(match.get_match_type()=="Test"){
	match.bowl_by_bowl(tbat, tbowl, toss,win1,win2,i,series,str,Working,series_winner,match_type);		//For Test Match
	}
	i++;
	}
	//fout.close();
}
if(user_choice==2){
	Match m1;
	str=new string[1];
if(match_type=="T20" || match_type=="ODI")
	m1.bowl_by_bowl(team1, team2, 'H',match_overs,win1,win2,0,1,str,1,series_winner);		//For T20 & ODI
else	
	m1.bowl_by_bowl(team1, team2,'H',win1,win2,0,1,str,1,series_winner,match_type);
}
	cout<<"\nDo you want to play again? (Y/N) = ";
	cin>>play_again;
}while(play_again=='Y'||play_again=='y');
    return 0;
}
