#pragma once

#include <map>
#include <vector>

#include "Candidate.h"

//! AutocompleteProvider allows for itself to be train via the "train" and "trainFromFile" methods.
//! This training is then used in order to provide feedback when the "getWords" method is invoked.
//! The more training data that is provided the better the candidate list provided will be.
class AutocompleteProvider
{
public:

    //! The minimum value for a valid character.
    static constexpr int MIN_VALID_CHAR = -1;

    //! The maximum value for a valid character.
    static constexpr int MAX_VALID_CHAR = 255;

    //! Default Constructor
    AutocompleteProvider();

    //! Copy Constructor
    //! @param[in] aCopy The AutocompleteProvider that you wish to copy from.
    AutocompleteProvider(const AutocompleteProvider & aCopy);

    //! Move Constructor
    //! @param[in] aCopy The AutocompleteProvider that you wish to move.
    AutocompleteProvider(const AutocompleteProvider && aCopy);

    //! Copy assignment operator
    //! @param[in] aCopy The AutocompleteProvider that you wish to copy from.
    //! @return A copy of the AutocompleteProvider.
    AutocompleteProvider & operator=(const AutocompleteProvider & aCopy);

    //! Move assignment operator
    //! @param[in] aCopy The AutocompleteProvider that you wish to move.
    //! @return A copy of the AutocompleteProvider.
    AutocompleteProvider & operator=(const AutocompleteProvider && aCopy);

    //! Provides a sorted list of candidate words for a given word fragment.
    //! The list is sorted based off the frequency it was found during training.
    //! @param[in] fragment The word fragment that you wish to get a candidate list for.
    //! @return             A sorted vector of all of the candidates found for the given fragment.
    std::vector<Candidate> getWords(std::string fragment);

    //! Trains the AutocompleteProvider with a given word or phrase.
    //! @param[in] passage A word or phrase to train the AutocompleteProvider with.
    void train(const std::string & passage);

    //! Trains the AutocompleteProvider with a given text file.
    //! 
    //! @note The given file must be co-located with the executable.
    //!
    //! @param[in] inFileName
    void trainFromFile(const std::string & inFileName);

private:

    //! The candidate map. Stores both the candidate word as well as the frequency that it
    //! showed up during the training. The string and the frequency will then be used to
    //! generate a candidate given a word fragment.
    std::map<std::string, int> CandidateMap_;
};