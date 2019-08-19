//
// Created by taylor on 4/12/18.
//

#include <fstream>
#include <Timer.hpp>
#include "Utils.hpp"
#include "GoSimilarity.hpp"

const string GoSimilarity::biogridGOFile = "go/gene2go";

GoSimilarity::GoSimilarity(Graph *G1, Graph *G2, const vector<double> &countWeights,
        double occurrencesFraction): occurrencesFraction(occurrencesFraction) {}

GoSimilarity::~GoSimilarity() {

}

string GoSimilarity::getGoSimpleFileName(const Graph &G) {
    string name = G.GetName();
    string goFile = "networks/"+name+"/go/"+name+"_gene_association.txt";
    ifstream test;
    try {
        test.open(goFile);
    } catch (...) {
        if(isBioGRIDNetwork(G)) {
            return "go/autogenerated/gene2go_simple.txt";
        }
        throw runtime_error("GO Data unavailable for this network");
    }
    return "networks/"+name+"/autogenerated"+name+"_go_simple.txt";

}
void GoSimilarity::ensureGoFileSimpleFormatExists(const Graph &G) {
    string name = G.GetName();
    string goFile = "networks/"+name+"/go/"+name+"_gene_association.txt";
    string GoSimpleFile;
    cout << "Computing " << getGoSimpleFileName(G) << "...";
    Timer T;
    T.start();
    if (Utils::checkFileExistsBool(goFile)) {
        GoSimpleFile = "networks/"+name+"/autogenerated/"+name+"_go_simple.txt";
        if (not Utils::checkFileExistsBool(GoSimpleFile)) {
            GoSimilarity::generateGOFileSimpleFormat(goFile, GoSimpleFile);
        }
    }
    else {
        GoSimpleFile = "go/autogenerated/gene2go_simple.txt";
        if (not Utils::checkFileExistsBool(GoSimpleFile)) {
            GoSimilarity::generateGene2GoSimpleFormat();
        }
    }
    cout << "GO simple format done (" << T.elapsedString() << ")" << endl;
}

vector<vector<uint> > GoSimilarity::loadGOTerms(const Graph &G, double occurrencesFraction) {
    return vector<vector<uint>>();
}

unordered_map<uint, uint> GoSimilarity::getGoCounts(const Graph &G) {
    return unordered_map<uint, uint>();
}

bool GoSimilarity::fulfillsPrereqs(Graph *G1, Graph *G2) {
    return false;
}

vector<uint> GoSimilarity::leastFrequentGoTerms(const Graph &G, double occurrencesFraction) {
    return vector<uint>();
}

void GoSimilarity::initSimMatrix() {

}

void GoSimilarity::assertNoRepeatedEntries(const vector<vector<uint> > &goTerms) {

}

void GoSimilarity::simpleToInternalFormat(const Graph &G, string GOFileSimpleFormat, string GOFileInternalFormat) {

}

void GoSimilarity::ensureGOFileInternalFormatExists(const Graph &G) {

}

ushort GoSimilarity::numberAnnotatedProteins(const Graph &G) {
    return 0;
}

void GoSimilarity::generateGOFileSimpleFormat(string GOFile, string GOFileSimpleFormat) {

}

void GoSimilarity::generateGene2GoSimpleFormat() {

}

bool GoSimilarity::isBioGRIDNetwork(const Graph &G) {
    return false;
}

bool GoSimilarity::hasGOData(const Graph &G) {
    return false;
}
