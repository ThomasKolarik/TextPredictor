#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>

#include "AutocompleteProvider.h"

//! The sort order for candidates when they are being returned. The higher the confidence the 
//! earlier it is sorted in the list.
//! @param[in] candidate1 The first candidate to compare.
//! @param[in] candidate2 The second candidate to compare.
//! @return True if candidate1 should be sorted before candidate2.
bool sortOrder(const Candidate & candidate1, const Candidate & candidate2)
{
    return candidate1.getConfidence() > candidate2.getConfidence();
}

//! Checks if the given character is not a letter.
//!
//! @note This also remove characters with values < MIN_VALID_CHAR &&  values > MAX_VALID_CHAR.
//!       This was done because the standard library does not like the extended Unicode character set.
//!
//! @param[in] c The value of the character.
//! @return True if the character is not a letter.
bool isNotLetter(int c)
{
    // Non-standard character break these standard library methods so remove them too.
    return c < AutocompleteProvider::MIN_VALID_CHAR || c > AutocompleteProvider::MAX_VALID_CHAR || !std::isalnum(c) || std::isdigit(c);
}

// Default Constructor
AutocompleteProvider::AutocompleteProvider() :
    CandidateMap_()
{
}

// Copy Constructor
// @param[in] aCopy The AutocompleteProvider that you wish to copy from.
AutocompleteProvider::AutocompleteProvider(const AutocompleteProvider & aCopy) :
    CandidateMap_(aCopy.CandidateMap_)
{
}

// Move Constructor
// @param[in] aCopy The AutocompleteProvider that you wish to move.
AutocompleteProvider::AutocompleteProvider(const AutocompleteProvider &&  aCopy) :
    CandidateMap_(std::move(aCopy.CandidateMap_))
{
}

// Copy assignment operator
// @param[in] aCopy The AutocompleteProvider that you wish to copy from.
// @return A copy of the AutocompleteProvider.
AutocompleteProvider & AutocompleteProvider::operator=(const AutocompleteProvider & aCopy)
{
    CandidateMap_ = aCopy.CandidateMap_;

    return *this;
}

// Move assignment operator
// @param[in] aCopy The AutocompleteProvider that you wish to move.
// @return A copy of the AutocompleteProvider.
AutocompleteProvider & AutocompleteProvider::operator=(const AutocompleteProvider && aCopy)
{
    CandidateMap_ = std::move(aCopy.CandidateMap_);

    return *this;
}

// Provides a sorted list of candidate words for a given word fragment.
// The list is sorted based off the frequency it was found during training.
// @param[in] fragment The word fragment that you wish to get a candidate list for.
// @return             A sorted vector of all of the candidates found for the given fragment.
std::vector<Candidate> AutocompleteProvider::getWords(std::string fragment)
{
    std::transform(fragment.begin(), fragment.end(), fragment.begin(), tolower);

    auto lowIt = CandidateMap_.lower_bound(fragment);

    //Increment the last letter of the fragment in order to create an upper bound.
    fragment[fragment.size() - 1] = fragment[fragment.size() - 1] + 1;

    auto upperIt = CandidateMap_.lower_bound(fragment);

    std::vector<Candidate> candidateList;

    for (auto it = lowIt; it != upperIt; ++it)
    {
        candidateList.push_back(Candidate(it->second, it->first));
    }

    // Sort the candidate list based on the confidence.
    std::sort(candidateList.begin(), candidateList.end(), sortOrder);

    return candidateList;
}

//! Trains the AutocompleteProvider with a given word or phrase.
//! @param[in] passage A word or phrase to train the AutocompleteProvider with.
void AutocompleteProvider::train(const std::string & passage)
{
    std::stringstream ss(passage);

    std::string temp;

    //Tokenize the string word by word using a string stream. Stripes all extraneous characters such as ",","'", etc.
    while (ss >> temp)
    {
        temp.erase(std::remove_if(temp.begin(), temp.end(), isNotLetter), temp.end());
        ++CandidateMap_[temp];
    }
}

//! Trains the AutocompleteProvider with a given text file.
//! 
//! @note The given file must be co-located with the executable.
//!
//! @param[in] inFileName
void AutocompleteProvider::trainFromFile(const std::string & inFileName)
{
    std::ifstream readFile(inFileName, std::ifstream::in);

    if (readFile.is_open())
    {
        std::string line;

        while (getline(readFile, line))
        {
            std::stringstream ss(line);

            std::string temp;

            //Tokenize the string word by word using a string stream. Stripes all extraneous characters such as ",","'", etc.
            while (ss >> temp)
            {
                temp.erase(std::remove_if(temp.begin(), temp.end(), isNotLetter), temp.end());
                ++CandidateMap_[temp];
            }
        }
    }
    else
    {
        std::cout << "Unable to find " << inFileName << std::endl;
    }
}
