#include "KnnAlgorithm.h"
#include "KnnAlgorithm.h"

/**
 * A default destructor.
 */
KnnAlgorithm::~KnnAlgorithm() = default;

/**
 * A constructor for the class who receives a catalog vector, number k, and a calculation distance object.
 */
KnnAlgorithm::KnnAlgorithm(vector<RelativeVector *> cataloged_vectors1,
                           vector<double> user_vector1,
                           unsigned long k_neighbors1,
                           AbstractDistance *calculation) {
    // Calling the setters.
    seCalc(calculation);
    setCataloged_vectors(std::move(cataloged_vectors1));
    setUserVector(std::move(user_vector1));
    setKNeighbors(k_neighbors1);
}

/**
 * Setter for cataloged_vectors.
 * @param catalogedVectors The vector of all RelativeVectors.
 */
void KnnAlgorithm::setCataloged_vectors(vector<RelativeVector *> cataloged_vectors1) {
    this->catalogedVectors = std::move(cataloged_vectors1);
}

/**
 * Setter for userVector.
 * @param userVector The user's vector.
 */
void KnnAlgorithm::setUserVector(vector<double> user_vector1) {
    this->userVector = std::move(user_vector1);
}

/**
 * Setter for the kNeighbors.
 * @param kNeighbors The k number.
 */
void KnnAlgorithm::setKNeighbors(unsigned long k_neighbors1) {
    this->kNeighbors = k_neighbors1;
}

/**
 * Setter for the calculation formula.
 * @param calculation1 The calculation formula.
 */
void KnnAlgorithm::seCalc(AbstractDistance *calculation1) {
    this->calc = calculation1;
}

/**
 * A getter for the k number.
 * @return the k number.
 */
unsigned long KnnAlgorithm::getKNeighbors() const {
    return this->kNeighbors;
}

/**
 * A double for the user's vector.
 * @return The user's vector.
 */
vector<double> KnnAlgorithm::getUserVector() {
    return this->userVector;
}

/**
 * A getter for the catalog vector.
 * @return The catalog vector.
 */
vector<RelativeVector *> KnnAlgorithm::getCatalogedVectors() {
    return catalogedVectors;
}

/**
 * A getter for the calculation member.
 * @return The calculation member.
 */
AbstractDistance *KnnAlgorithm::getCalc() {
    return this->calc;
}

/**
 * The function check if two vectors are equally sized.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return A boolean true if they are equally sized, false otherwise.
 */
bool KnnAlgorithm::sizeComparison(const vector<double> &v1, const vector<double> &v2) {
    // Checking if the vectors have the same size.
    return (v1.size() == v2.size());
}

/**
 * Calculate the distance between all vectors to the userVector and set them the result.
 * @return true if the calculation worked, false otherwise.
 */
bool KnnAlgorithm::calculateDistances() {
    // This for loop calc the distance between userVector(user input) to all the cataloged vectors.
    for (int i = 0; i < getCatalogedVectors().size(); i++) {
        // Checking if the vectors in the same size.
        if(!sizeComparison(getCatalogedVectors()[i]->getValuesVector(), getUserVector())){
            return false;
        }
        // Set the result of the distance between the user's vector to the ith vector.
        double result = getCalc()->calculateDistance(getCatalogedVectors()[i]->getValuesVector(), getUserVector());
        // Set the result to the ith vector.
        getCatalogedVectors()[i]->setDistanceFromRelativeVec(result);
    }
    return true;
}

/**
 * A comparator for the sort function between to RelativeVectors by their distance value.
 * @param v1 The first RelativeVector.
 * @param v2 The second RelativeVector.
 * @return True if the distance of v1's distance is lower then v2's, False otherwise.
 */
bool compareRelativeVector(RelativeVector *v1, RelativeVector *v2) {
    return (v1->getDistanceFromRelativeVec() < v2->getDistanceFromRelativeVec());
}

/**
 * Sorting the vector of RelativeVectors, taking only the first k elements.
 * @return A vector of the k smallest by distance elements.
 */
vector<RelativeVector *> KnnAlgorithm::sortingAndGettingK() {
    // Set the CatalogVectors to a temp vector.
    vector<RelativeVector *> knn = getCatalogedVectors();
    // Sort the array by the given compare function.
    sort(knn.begin(), knn.end(), compareRelativeVector);
    // Set the knn to the catalog vector.
    setCataloged_vectors(knn);
    // Create a new vector.
    vector<RelativeVector *> kRelativeVectors;
    // Push to it the first k elements.
    unsigned long kNum = min(getKNeighbors(), knn.size());
    for (int i = 0; i < kNum; i++) {
        kRelativeVectors.push_back(knn[i]);
    }
    // Return the first k elements.
    return kRelativeVectors;
}

/**
 * Create a map contains the string of classification as a key and the number it appears in knn as a value.
 * @param knn The k nearest neighbours to the user's vector.
 * @return A map contains the string of classification as a key and the number it appears in knn as a value.
 */
map<string, int> KnnAlgorithm::createMap(vector<RelativeVector *> knn) {
    // Declare a map.
    map<string, int> kMap;
    for (int i = 0; i < knn.size(); i++) {
        // If the classification is in the map.
        if (kMap.find(knn[i]->getClassification()) != kMap.end()) {
            // Add one to the value.
            kMap[knn[i]->getClassification()] += 1;
            // If it's not.
        } else {
            // add the classification with the value 1.
            kMap[knn[i]->getClassification()] = 1;
        }
    }
    // Return the map.
    return kMap;
}

/**
 * Check what key has the biggest value, and return it's classification.
 * @param kMap Tha map of values.
 * @return the classification the biggest value.
 */
string KnnAlgorithm::extractClassification(const map<string, int> &kMap) {
    // A counter for the biggest classification.
    int maxClass = 0;
    // The result classification.
    string resultClass;
    // Iterate all keys.
    for (auto const &keyValue: kMap) {
        // If the value is larger than the counter, replace them.
        if (keyValue.second > maxClass) {
            maxClass = keyValue.second;
            resultClass = keyValue.first;
        }
    }
    // Return the largest classification.
    return resultClass;
}

/**
 * Deleting all relative vector's data.
 */
void KnnAlgorithm::destroyKnn() {
    for (auto &i: catalogedVectors) {
        delete i;
    }
}

/**
 * A control flow function for this class calculations.
 * @return the largest classification from the KNN vectors.
 */
string KnnAlgorithm::classificationUserVec() {
    // Calculate all distances of vectors from the user's vector.
    if(!calculateDistances()){
        return "invalid input";
    }
    // Calculate the k nearest neighbors.
    vector<RelativeVector *> nearestK = sortingAndGettingK();
    // Create a map from the knn.
    map<string, int> kMap = createMap(nearestK);
    // Destroy the KNN vector.
    // destroyKnn();
    // Calculate the largest classification and return it.
    return extractClassification(kMap);
}
