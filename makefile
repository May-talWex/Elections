Ass5: DemocraticLeaderPolitician.o RepublicanLeaderPolitician.o DemocraticSocialPolitician.o RepublicanSocialPolitician.o DemocraticParty.o RepublicanParty.o main.o Politician.o Party.o PoliticalSys.o SocialPolitician.o LeaderPolitician.o
	g++ -o Ass5 DemocraticLeaderPolitician.o RepublicanLeaderPolitician.o DemocraticSocialPolitician.o RepublicanSocialPolitician.o DemocraticParty.o RepublicanParty.o main.o Politician.o Party.o PoliticalSys.o SocialPolitician.o LeaderPolitician.o
DemocraticLeaderPolitician.o: DemocraticLeaderPolitician.h DemocraticLeaderPolitician.cpp LeaderPolitician.h
	g++ -Wall -g -c DemocraticLeaderPolitician.cpp -o DemocraticLeaderPolitician.o
RepublicanLeaderPolitician.o: RepublicanLeaderPolitician.h RepublicanLeaderPolitician.cpp LeaderPolitician.h
	g++ -Wall -g -c RepublicanLeaderPolitician.cpp -o RepublicanLeaderPolitician.o
DemocraticSocialPolitician.o: DemocraticSocialPolitician.h DemocraticSocialPolitician.cpp SocialPolitician.h
	g++ -Wall -g -c DemocraticSocialPolitician.cpp -o DemocraticSocialPolitician.o
RepublicanSocialPolitician.o: RepublicanSocialPolitician.h RepublicanSocialPolitician.cpp SocialPolitician.h
	g++ -Wall -g -c RepublicanSocialPolitician.cpp -o RepublicanSocialPolitician.o
DemocraticParty.o: DemocraticParty.h DemocraticParty.cpp Party.h
	g++ -Wall -g -c DemocraticParty.cpp -o DemocraticParty.o
RepublicanParty.o: RepublicanParty.h RepublicanParty.cpp Party.h
	g++ -Wall -g -c RepublicanParty.cpp -o RepublicanParty.o
main.o: main.cpp PoliticalSys.h Error.h
	g++ -Wall -g -c main.cpp -o main.o
Politician.o: Politician.h Politician.cpp
	g++ -Wall -g -c Politician.cpp -o Politician.o
Party.o: Party.h Party.cpp
	g++ -Wall -g -c Party.cpp -o Party.o
PoliticalSys.o: PoliticalSys.h PoliticalSys.cpp
	g++ -Wall -g -c PoliticalSys.cpp -o PoliticalSys.o
SocialPolitician.o: SocialPolitician.h SocialPolitician.cpp Politician.h
	g++ -Wall -g -c SocialPolitician.cpp -o SocialPolitician.o
LeaderPolitician.o: LeaderPolitician.h LeaderPolitician.cpp Politician.h
	g++ -Wall -g -c LeaderPolitician.cpp -o LeaderPolitician.o
clean:
	rm -f *.o