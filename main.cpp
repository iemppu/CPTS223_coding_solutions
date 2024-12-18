#include <map>
// #include <unordered_map>
#include <cassert>
#include "generate_users.hpp"
using namespace std;


map<string, User> buildMapByUserName(vector<User> users) {
    map<string, User> usersMap;
    for (int i = 0; i < users.size(); ++i)
    {
        usersMap[users[i].userName] = users[i];
    }
    return usersMap;
}


map<string, User> buildMapByEmail(vector<User> users) {
    map<string, User> usersMap;
    for (int i = 0; i < users.size(); ++i)
    {
        usersMap[users[i].email] = users[i];
    }
    return usersMap;
}

void printMap(map<string, User> aMap) {
    int i = 0;
    for (auto elem : aMap) {
        cout << "#" << i << ". Key: " << elem.first << ", Value: ";
        printAUser(elem.second);
        i++;
    }
}

bool isMapSorted(map<string, User> aMap) {
    if ( aMap.empty() )
        return true;

    map<string, User>::iterator iter = aMap.begin();
    map<string, User>::iterator prev = iter;  
    ++iter; 

    while ( iter != aMap.end() ) {
        if ( iter->first <= prev->first ) {
            return false;
        }
        prev = iter; 
        ++iter; 
    }
    return true;

}

bool testSearchByKey(map<string, User>& aMap, string keyToSearch) {
    auto iter = aMap.find(keyToSearch);

    if (iter != aMap.end())
        return true; 
    else
        return false; 
}

bool testDeleteByKey(map<string, User> aMap, string keyToDelete) {
    auto iter = aMap.find(keyToDelete);

    if (iter == aMap.end()) 
        return false;
    else {
        aMap.erase(keyToDelete);
        iter = aMap.find(keyToDelete);
        if (iter == aMap.end())
            return true; 
        else
            return false; 
    }
}

void printActiveUsers(map<string, User> aMap) {
    int activeThreshold = 800;
    for ( auto iter = aMap.begin(); iter != aMap.end(); iter++) {
        if ( activeThreshold < iter->second.numPosts )
            cout << iter->second.userName << ": " << iter->second.numPosts << " tweets" << endl;
    }
}

void printMostPopularCategory(map<string, User> aMap) {
    map<string, int> categoryMap;
    for ( auto iter = aMap.begin(); iter != aMap.end(); iter++ ) {
        categoryMap[iter->second.mostViewedCategory]++;
    }
    string mostPopularCategory;
    int num;
    for ( auto iter = categoryMap.begin(); iter != categoryMap.end(); iter++ ) {
        if ( num < iter->second ) {
            num = iter->second;
            mostPopularCategory = iter->first;
        }
    }
    cout << "The most popular category is " << mostPopularCategory << ", which is " << num << " users' most viewed category." << endl;
}



void testBuildMap(map<string, User>* mapByUserName, int numUsers) {
	cout << "Run test: build the map" << endl;
    if (mapByUserName == nullptr) {
        cout << "Error: Null pointer received." << endl;
        assert(false && "Null pointer received");
        return;
    }
    else {
        assert(mapByUserName->size() == static_cast<size_t>(numUsers));
        cout << "Test build the map passed" << endl;
        return;
    }
}



int main(int argc, char** argv)
{
	std::map<int, std::string> myMap = {{1, "one"}, {2, "two"}, {3, "three"}};

    int keyToCheck = 2;
	
    int numUsers = 10;
    vector<User> users = generateUsers(numUsers);


    cout << "Build map with username as key" << endl;
    map<string, User> mapByUserName = buildMapByUserName(users);
    cout << "Build map with email as key" << endl;
    map<string, User> mapByEmail = buildMapByEmail(users);

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <testName>" << std::endl;
        return 1;
    }

    std::string testName = argv[1];

    try {
        if (testName == "TestBuildMap") {
            testBuildMap(&mapByUserName, numUsers);
            testBuildMap(&mapByEmail, numUsers);
		}
		else if (testName == "TestPrintByUserName") {
			cout << "Print \"mapByUserName\" map:" << endl;
			printMap(mapByUserName);
			cout << endl;
		}
		else if (testName == "TestSearchByKey") {
		    cout << "Run test: Search by key" << endl;
			string keyToSearch = "rangerPower";

			cout << "mapByUserName contains keyToSearch: " 
				<< (mapByUserName.find(keyToSearch) != mapByUserName.end()) << endl;

			auto it = mapByUserName.find(keyToSearch);
			if (it != mapByUserName.end()) {
			    std::cout << "kk passed" << std::endl;
			}
			else {
			    std::cout << "kk failed" << std::endl;
			}
			
			assert(it != mapByUserName.end());
						
			// assert(!mapByUserName.empty());
			
			if (mapByUserName.find(keyToSearch) != mapByUserName.end()) {
				std::cout << "kkk passed" << std::endl;
			}
			else {
				std::cerr << "Key does not exist in the map!" << std::endl;
    			return EXIT_FAILURE;
			}
		    // assert( it != mapByUserName.end() );
				
			// keyToSearch = "lexi55";
			// assert( testSearchByKey(mapByUserName, keyToSearch) == 1 );
			
			// keyToSearch = "kat@gmail.com";
			// assert( testSearchByKey(mapByUserName, keyToSearch) == 1 );
			// assert( testSearchByKey(mapByEmail, keyToSearch) == 0 );
		    
			cout << "Test Search by key Passed" << endl;

		}
		else if (testName == "TestDeleteByKey") {
		    cout << "Run test: Delete by key" << endl;
			string keyToDelete = "lexi5";
		    // assert(testDeleteByKey(mapByUserName, keyToDelete) == 1);

   //  		keyToDelete = "kat@gmail.com";
			// assert(testDeleteByKey(mapByEmail, keyToDelete) == 1);
				
		 //    cout << "Test Delete by key Passed" << endl;
		}
		else if (testName == "TestSortedKey") {
			cout << "Run test if map's key is sorted" << endl;
		    assert(isMapSorted(mapByUserName) == 1);
		    cout << "Test Sorted Key Passed" << endl;

		}
		else if (testName == "TestPrintActiveUsers") {
		    cout << "Run test print usernames with more than 800 tweets:" << endl;
		    printActiveUsers(mapByUserName);
		    cout << endl;
			
		}
		else if (testName == "TestPrintMostPopularCategory") {
		    cout << "Run test print the most popular category" << endl;
		    printMostPopularCategory(mapByUserName);
		    cout << endl;
        } else {
            std::cerr << "Unknown test: " << testName << std::endl;
            return 1;
        }

        std::cout << "Test Passed: " << testName << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test Failed: " << testName << " - " << e.what() << std::endl;
        return 1;
    }


    return 0;
}
