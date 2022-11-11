#include "Project2.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
	To check output (At the Project1 directory):
		g++ -std=c++17 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/

TEST_CASE("Provided Test 1", "[flag]"){
	vector<pair<string, string>> edges; 
	int power_iterations;
	map<string, string> rank_matrix_expected;

	power_iterations = 5;
	edges.push_back(make_pair("google.com", "gmail.com"));
	edges.push_back(make_pair("google.com", "maps.com"));
	edges.push_back(make_pair("facebook.com", "ufl.edu"));
	edges.push_back(make_pair("ufl.edu", "google.com"));
	edges.push_back(make_pair("ufl.edu", "gmail.com"));
	edges.push_back(make_pair("maps.com", "facebook.com"));
	edges.push_back(make_pair("maps.com", "quora.com"));

	rank_matrix_expected["facebook.com"] = "0.02";
	rank_matrix_expected["gmail.com"] = "0.04";
	rank_matrix_expected["google.com"] = "0.02";
	rank_matrix_expected["maps.com"] = "0.02";
	rank_matrix_expected["quora.com"] = "0.02";
	rank_matrix_expected["ufl.edu"] = "0.02";

	AdjacencyList a_list(edges);
    map<string, string> rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
}

TEST_CASE("Provided Test 2", "[flag]"){
	vector<pair<string, string>> edges; 
	int power_iterations;
	map<string, string> rank_matrix_expected;

	power_iterations = 1;
	edges.push_back(make_pair("google.com", "gmail.com"));
	edges.push_back(make_pair("google.com", "maps.com"));
	edges.push_back(make_pair("facebook.com", "ufl.edu"));
	edges.push_back(make_pair("ufl.edu", "google.com"));
	edges.push_back(make_pair("ufl.edu", "gmail.com"));
	edges.push_back(make_pair("maps.com", "facebook.com"));
	edges.push_back(make_pair("quoa.co", "maps.edu"));
	edges.push_back(make_pair("maps.com", "quora.com"));
	edges.push_back(make_pair("quora.com", "ufl.com"));
	edges.push_back(make_pair("quora.com", "facebok.co.in"));
	edges.push_back(make_pair("quora.com", "quoa.co"));

	rank_matrix_expected["facebok.co.in"] = "0.10";
	rank_matrix_expected["facebook.com"] = "0.10";
	rank_matrix_expected["gmail.com"] = "0.10";
	rank_matrix_expected["google.com"] = "0.10";
	rank_matrix_expected["maps.com"] = "0.10";
	rank_matrix_expected["maps.edu"] = "0.10";
	rank_matrix_expected["quoa.co"] = "0.10";
	rank_matrix_expected["quora.com"] = "0.10";
	rank_matrix_expected["ufl.com"] = "0.10";
	rank_matrix_expected["ufl.edu"] = "0.10";

	AdjacencyList a_list(edges);
    map<string, string> rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
}

TEST_CASE("Provided Test 3", "[flag]"){
	vector<pair<string, string>> edges; 
	int power_iterations;
	map<string, string> rank_matrix_expected;

	power_iterations = 3;
	edges.push_back(make_pair("google.com", "gmail.com"));
	edges.push_back(make_pair("google.com", "maps.com"));
	edges.push_back(make_pair("facebook.com", "ufl.edu"));
	edges.push_back(make_pair("ufl.edu", "google.com"));
	edges.push_back(make_pair("ufl.edu", "gmail.com"));
	edges.push_back(make_pair("maps.com", "facebook.com"));
	edges.push_back(make_pair("gmail.com", "maps.com"));

	rank_matrix_expected["facebook.com"] = "0.30";
	rank_matrix_expected["gmail.com"] = "0.15";
	rank_matrix_expected["google.com"] = "0.10";
	rank_matrix_expected["maps.com"] = "0.25";
	rank_matrix_expected["ufl.edu"] = "0.20";

	AdjacencyList a_list(edges);
    map<string, string> rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
}

TEST_CASE("Provided Test 4", "[flag]"){
	vector<pair<string, string>> edges; 
	int power_iterations;
	map<string, string> rank_matrix_expected;

	power_iterations = 10000;
	edges.push_back(make_pair("google.com", "gmail.com"));
	edges.push_back(make_pair("google.com", "maps.com"));
	edges.push_back(make_pair("facebook.com", "ufl.edu"));
	edges.push_back(make_pair("ufl.edu", "google.com"));
	edges.push_back(make_pair("ufl.edu", "gmail.com"));
	edges.push_back(make_pair("maps.com", "facebook.com"));
	edges.push_back(make_pair("gmail.com", "maps.com"));

	rank_matrix_expected["facebook.com"] = "0.24";
	rank_matrix_expected["gmail.com"] = "0.18";
	rank_matrix_expected["google.com"] = "0.12";
	rank_matrix_expected["maps.com"] = "0.24";
	rank_matrix_expected["ufl.edu"] = "0.24";

	AdjacencyList a_list(edges);
    map<string, string> rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
}

TEST_CASE("Provided Test 5", "[flag]"){
	vector<pair<string, string>> edges; 
	int power_iterations;
	map<string, string> rank_matrix_expected;

	power_iterations = 2;
	edges.push_back(make_pair("google.com", "gmail.com"));
	edges.push_back(make_pair("google.com", "maps.com"));
	edges.push_back(make_pair("facebook.com", "ufl.edu"));
	edges.push_back(make_pair("ufl.edu", "google.com"));
	edges.push_back(make_pair("ufl.edu", "gmail.com"));
	edges.push_back(make_pair("maps.com", "facebook.com"));
	edges.push_back(make_pair("gmail.com", "maps.com"));

	rank_matrix_expected["facebook.com"] = "0.20";
	rank_matrix_expected["gmail.com"] = "0.20";
	rank_matrix_expected["google.com"] = "0.10";
	rank_matrix_expected["maps.com"] = "0.30";
	rank_matrix_expected["ufl.edu"] = "0.20";

	AdjacencyList a_list(edges);
    map<string, string> rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
}

TEST_CASE("Generated Test 6", "[flag]"){
	vector<pair<string, string>> edges; 
	int power_iterations;
	map<string, string> rank_matrix_expected;
	map<string, string> rank_matrix_actual;

	
	edges.push_back(make_pair("0", "1"));
	edges.push_back(make_pair("1", "4"));
	edges.push_back(make_pair("1", "5"));
	edges.push_back(make_pair("2", "4"));
	edges.push_back(make_pair("3", "2"));
	edges.push_back(make_pair("3", "5"));
	edges.push_back(make_pair("4", "3"));
	edges.push_back(make_pair("4", "5"));
	edges.push_back(make_pair("5", "3"));

	AdjacencyList a_list(edges);

	////---------------------------------------------------------------------------
	power_iterations = 2;
	rank_matrix_expected["0"] = "0.00";
	rank_matrix_expected["1"] = "0.17";
	rank_matrix_expected["2"] = "0.08";
	rank_matrix_expected["3"] = "0.25";
	rank_matrix_expected["4"] = "0.25";
	rank_matrix_expected["5"] = "0.25";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 3;
	rank_matrix_expected["0"] = "0.00";
	rank_matrix_expected["1"] = "0.00";
	rank_matrix_expected["2"] = "0.13";
	rank_matrix_expected["3"] = "0.38";
	rank_matrix_expected["4"] = "0.17";
	rank_matrix_expected["5"] = "0.33";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 4;
	rank_matrix_expected["0"] = "0.00";
	rank_matrix_expected["1"] = "0.00";
	rank_matrix_expected["2"] = "0.19";
	rank_matrix_expected["3"] = "0.42";
	rank_matrix_expected["4"] = "0.13";
	rank_matrix_expected["5"] = "0.27";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 100;
	rank_matrix_expected["0"] = "0.00";
	rank_matrix_expected["1"] = "0.00";
	rank_matrix_expected["2"] = "0.18";
	rank_matrix_expected["3"] = "0.36";
	rank_matrix_expected["4"] = "0.18";
	rank_matrix_expected["5"] = "0.27";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 10000;
	rank_matrix_expected["0"] = "0.00";
	rank_matrix_expected["1"] = "0.00";
	rank_matrix_expected["2"] = "0.18";
	rank_matrix_expected["3"] = "0.36";
	rank_matrix_expected["4"] = "0.18";
	rank_matrix_expected["5"] = "0.27";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------
}

TEST_CASE("Generated Test 7", "[flag]"){
	vector<pair<string, string>> edges; 
	int power_iterations;
	map<string, string> rank_matrix_expected;
	map<string, string> rank_matrix_actual;

	
	edges.push_back(make_pair("0", "1"));
	edges.push_back(make_pair("1", "2"));
	edges.push_back(make_pair("2", "3"));
	edges.push_back(make_pair("3", "4"));
	edges.push_back(make_pair("4", "0"));

	AdjacencyList a_list(edges);

	////---------------------------------------------------------------------------
	power_iterations = 2;
	rank_matrix_expected["0"] = "0.20";
	rank_matrix_expected["1"] = "0.20";
	rank_matrix_expected["2"] = "0.20";
	rank_matrix_expected["3"] = "0.20";
	rank_matrix_expected["4"] = "0.20";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 10000;
	rank_matrix_expected["0"] = "0.20";
	rank_matrix_expected["1"] = "0.20";
	rank_matrix_expected["2"] = "0.20";
	rank_matrix_expected["3"] = "0.20";
	rank_matrix_expected["4"] = "0.20";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------
}

TEST_CASE("Generated Test 8", "[flag]"){
	vector<pair<string, string>> edges; 
	int power_iterations;
	map<string, string> rank_matrix_expected;
	map<string, string> rank_matrix_actual;

	
	edges.push_back(make_pair("0", "5"));
	edges.push_back(make_pair("1", "0"));
	edges.push_back(make_pair("2", "0"));
	edges.push_back(make_pair("3", "0"));
	edges.push_back(make_pair("4", "0"));
	edges.push_back(make_pair("5", "0"));

	AdjacencyList a_list(edges);

	////---------------------------------------------------------------------------
	power_iterations = 2;
	rank_matrix_expected["0"] = "0.83";
	rank_matrix_expected["1"] = "0.00";
	rank_matrix_expected["2"] = "0.00";
	rank_matrix_expected["3"] = "0.00";
	rank_matrix_expected["4"] = "0.00";
	rank_matrix_expected["5"] = "0.17";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 3;
	rank_matrix_expected["0"] = "0.17";
	rank_matrix_expected["1"] = "0.00";
	rank_matrix_expected["2"] = "0.00";
	rank_matrix_expected["3"] = "0.00";
	rank_matrix_expected["4"] = "0.00";
	rank_matrix_expected["5"] = "0.83";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 4;
	rank_matrix_expected["0"] = "0.83";
	rank_matrix_expected["1"] = "0.00";
	rank_matrix_expected["2"] = "0.00";
	rank_matrix_expected["3"] = "0.00";
	rank_matrix_expected["4"] = "0.00";
	rank_matrix_expected["5"] = "0.17";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------
}

TEST_CASE("Generated Test 9", "[flag]"){
	vector<pair<string, string>> edges; 
	int power_iterations;
	map<string, string> rank_matrix_expected;
	map<string, string> rank_matrix_actual;

	
	edges.push_back(make_pair("0", "1"));
	edges.push_back(make_pair("1", "2"));
	edges.push_back(make_pair("1", "0"));
	edges.push_back(make_pair("2", "1"));

	AdjacencyList a_list(edges);

	////---------------------------------------------------------------------------
	power_iterations = 2;
	rank_matrix_expected["0"] = "0.17";
	rank_matrix_expected["1"] = "0.67";
	rank_matrix_expected["2"] = "0.17";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 3;
	rank_matrix_expected["0"] = "0.33";
	rank_matrix_expected["1"] = "0.33";
	rank_matrix_expected["2"] = "0.33";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 4;
	rank_matrix_expected["0"] = "0.17";
	rank_matrix_expected["1"] = "0.67";
	rank_matrix_expected["2"] = "0.17";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------
}

TEST_CASE("Generated Test 10", "[flag]"){
	vector<pair<string, string>> edges; 
	int power_iterations;
	map<string, string> rank_matrix_expected;
	map<string, string> rank_matrix_actual;

	
	edges.push_back(make_pair("0", "3"));
	edges.push_back(make_pair("0", "1"));
	edges.push_back(make_pair("1", "2"));
	edges.push_back(make_pair("1", "3"));
	edges.push_back(make_pair("1", "7"));
	edges.push_back(make_pair("2", "1"));
	edges.push_back(make_pair("2", "3"));
	edges.push_back(make_pair("2", "5"));
	edges.push_back(make_pair("2", "7"));
	edges.push_back(make_pair("3", "4"));
	edges.push_back(make_pair("3", "5"));
	edges.push_back(make_pair("3", "6"));
	edges.push_back(make_pair("4", "0"));
	edges.push_back(make_pair("5", "0"));
	edges.push_back(make_pair("5", "1"));
	edges.push_back(make_pair("5", "6"));
	edges.push_back(make_pair("5", "7"));
	edges.push_back(make_pair("6", "0"));
	edges.push_back(make_pair("6", "2"));
	edges.push_back(make_pair("7", "0"));
	edges.push_back(make_pair("7", "6"));

	AdjacencyList a_list(edges);

	////---------------------------------------------------------------------------
	power_iterations = 2;
	rank_matrix_expected["0"] = "0.28";
	rank_matrix_expected["1"] = "0.13";
	rank_matrix_expected["2"] = "0.10";
	rank_matrix_expected["3"] = "0.14";
	rank_matrix_expected["4"] = "0.04";
	rank_matrix_expected["5"] = "0.07";
	rank_matrix_expected["6"] = "0.14";
	rank_matrix_expected["7"] = "0.10";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 3;
	rank_matrix_expected["0"] = "0.18";
	rank_matrix_expected["1"] = "0.18";
	rank_matrix_expected["2"] = "0.11";
	rank_matrix_expected["3"] = "0.21";
	rank_matrix_expected["4"] = "0.05";
	rank_matrix_expected["5"] = "0.07";
	rank_matrix_expected["6"] = "0.12";
	rank_matrix_expected["7"] = "0.09";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 4;
	rank_matrix_expected["0"] = "0.16";
	rank_matrix_expected["1"] = "0.14";
	rank_matrix_expected["2"] = "0.12";
	rank_matrix_expected["3"] = "0.18";
	rank_matrix_expected["4"] = "0.07";
	rank_matrix_expected["5"] = "0.10";
	rank_matrix_expected["6"] = "0.13";
	rank_matrix_expected["7"] = "0.11";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 5;
	rank_matrix_expected["0"] = "0.21";
	rank_matrix_expected["1"] = "0.14";
	rank_matrix_expected["2"] = "0.11";
	rank_matrix_expected["3"] = "0.16";
	rank_matrix_expected["4"] = "0.06";
	rank_matrix_expected["5"] = "0.09";
	rank_matrix_expected["6"] = "0.14";
	rank_matrix_expected["7"] = "0.10";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 10;
	rank_matrix_expected["0"] = "0.19";
	rank_matrix_expected["1"] = "0.15";
	rank_matrix_expected["2"] = "0.11";
	rank_matrix_expected["3"] = "0.18";
	rank_matrix_expected["4"] = "0.06";
	rank_matrix_expected["5"] = "0.09";
	rank_matrix_expected["6"] = "0.13";
	rank_matrix_expected["7"] = "0.10";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 100;
	rank_matrix_expected["0"] = "0.19";
	rank_matrix_expected["1"] = "0.15";
	rank_matrix_expected["2"] = "0.11";
	rank_matrix_expected["3"] = "0.17";
	rank_matrix_expected["4"] = "0.06";
	rank_matrix_expected["5"] = "0.09";
	rank_matrix_expected["6"] = "0.13";
	rank_matrix_expected["7"] = "0.10";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 10000;
	rank_matrix_expected["0"] = "0.19";
	rank_matrix_expected["1"] = "0.15";
	rank_matrix_expected["2"] = "0.11";
	rank_matrix_expected["3"] = "0.17";
	rank_matrix_expected["4"] = "0.06";
	rank_matrix_expected["5"] = "0.09";
	rank_matrix_expected["6"] = "0.13";
	rank_matrix_expected["7"] = "0.10";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------
}

TEST_CASE("Generated Test 11", "[flag]"){
	vector<pair<string, string>> edges; 
	int power_iterations;
	map<string, string> rank_matrix_expected;
	map<string, string> rank_matrix_actual;

	
	edges.push_back(make_pair("0", "1"));
	edges.push_back(make_pair("1", "0"));

	AdjacencyList a_list(edges);

	////---------------------------------------------------------------------------
	power_iterations = 2;
	rank_matrix_expected["0"] = "0.50";
	rank_matrix_expected["1"] = "0.50";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 8;
	rank_matrix_expected["0"] = "0.50";
	rank_matrix_expected["1"] = "0.50";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 10000;
	rank_matrix_expected["0"] = "0.50";
	rank_matrix_expected["1"] = "0.50";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------
}

TEST_CASE("Generated Test 12", "[flag]"){
	vector<pair<string, string>> edges; 
	int power_iterations;
	map<string, string> rank_matrix_expected;
	map<string, string> rank_matrix_actual;

	
	edges.push_back(make_pair("0", "1"));
	edges.push_back(make_pair("0", "3"));
	edges.push_back(make_pair("1", "2"));
	edges.push_back(make_pair("2", "3"));
	edges.push_back(make_pair("3", "4"));
	edges.push_back(make_pair("4", "0"));

	AdjacencyList a_list(edges);

	////---------------------------------------------------------------------------
	power_iterations = 2;
	rank_matrix_expected["0"] = "0.20";
	rank_matrix_expected["1"] = "0.10";
	rank_matrix_expected["2"] = "0.20";
	rank_matrix_expected["3"] = "0.30";
	rank_matrix_expected["4"] = "0.20";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 3;
	rank_matrix_expected["0"] = "0.20";
	rank_matrix_expected["1"] = "0.10";
	rank_matrix_expected["2"] = "0.10";
	rank_matrix_expected["3"] = "0.30";
	rank_matrix_expected["4"] = "0.30";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 4;
	rank_matrix_expected["0"] = "0.30";
	rank_matrix_expected["1"] = "0.10";
	rank_matrix_expected["2"] = "0.10";
	rank_matrix_expected["3"] = "0.20";
	rank_matrix_expected["4"] = "0.30";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 5;
	rank_matrix_expected["0"] = "0.30";
	rank_matrix_expected["1"] = "0.15";
	rank_matrix_expected["2"] = "0.10";
	rank_matrix_expected["3"] = "0.25";
	rank_matrix_expected["4"] = "0.20";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 10;
	rank_matrix_expected["0"] = "0.28";
	rank_matrix_expected["1"] = "0.13";
	rank_matrix_expected["2"] = "0.13";
	rank_matrix_expected["3"] = "0.25";
	rank_matrix_expected["4"] = "0.23";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 100;
	rank_matrix_expected["0"] = "0.25";
	rank_matrix_expected["1"] = "0.12";
	rank_matrix_expected["2"] = "0.12";
	rank_matrix_expected["3"] = "0.25";
	rank_matrix_expected["4"] = "0.25";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------
}

TEST_CASE("Generated Test 13", "[flag]"){
	vector<pair<string, string>> edges; 
	int power_iterations;
	map<string, string> rank_matrix_expected;
	map<string, string> rank_matrix_actual;

	
	edges.push_back(make_pair("0", "3"));
	edges.push_back(make_pair("1", "3"));
	edges.push_back(make_pair("2", "0"));
	edges.push_back(make_pair("2", "1"));
	edges.push_back(make_pair("3", "2"));

	AdjacencyList a_list(edges);

	////---------------------------------------------------------------------------
	power_iterations = 2;
	rank_matrix_expected["0"] = "0.13";
	rank_matrix_expected["1"] = "0.13";
	rank_matrix_expected["2"] = "0.25";
	rank_matrix_expected["3"] = "0.50";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 3;
	rank_matrix_expected["0"] = "0.13";
	rank_matrix_expected["1"] = "0.13";
	rank_matrix_expected["2"] = "0.50";
	rank_matrix_expected["3"] = "0.25";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 4;
	rank_matrix_expected["0"] = "0.25";
	rank_matrix_expected["1"] = "0.25";
	rank_matrix_expected["2"] = "0.25";
	rank_matrix_expected["3"] = "0.25";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 10;
	rank_matrix_expected["0"] = "0.25";
	rank_matrix_expected["1"] = "0.25";
	rank_matrix_expected["2"] = "0.25";
	rank_matrix_expected["3"] = "0.25";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------
}

TEST_CASE("Generated Test 14", "[flag]"){
	vector<pair<string, string>> edges; 
	int power_iterations;
	map<string, string> rank_matrix_expected;
	map<string, string> rank_matrix_actual;

	
	edges.push_back(make_pair("0", "1"));
	edges.push_back(make_pair("0", "2"));
	edges.push_back(make_pair("0", "3"));
	edges.push_back(make_pair("1", "2"));
	edges.push_back(make_pair("2", "1"));
	edges.push_back(make_pair("3", "0"));

	AdjacencyList a_list(edges);

	////---------------------------------------------------------------------------
	power_iterations = 2;
	rank_matrix_expected["0"] = "0.25";
	rank_matrix_expected["1"] = "0.33";
	rank_matrix_expected["2"] = "0.33";
	rank_matrix_expected["3"] = "0.08";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 3;
	rank_matrix_expected["0"] = "0.08";
	rank_matrix_expected["1"] = "0.42";
	rank_matrix_expected["2"] = "0.42";
	rank_matrix_expected["3"] = "0.08";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 4;
	rank_matrix_expected["0"] = "0.08";
	rank_matrix_expected["1"] = "0.44";
	rank_matrix_expected["2"] = "0.44";
	rank_matrix_expected["3"] = "0.03";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 5;
	rank_matrix_expected["0"] = "0.03";
	rank_matrix_expected["1"] = "0.47";
	rank_matrix_expected["2"] = "0.47";
	rank_matrix_expected["3"] = "0.02";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------

	////---------------------------------------------------------------------------
	power_iterations = 10000;
	rank_matrix_expected["0"] = "0.00";
	rank_matrix_expected["1"] = "0.50";
	rank_matrix_expected["2"] = "0.50";
	rank_matrix_expected["3"] = "0.00";

    rank_matrix_actual = a_list.CalculatePageRank(power_iterations);

	for(auto r: rank_matrix_actual){
		REQUIRE(rank_matrix_expected.find(r.first) != rank_matrix_expected.end());
		REQUIRE(rank_matrix_actual[r.first] == rank_matrix_expected[r.first]);
	}
	////---------------------------------------------------------------------------
}
