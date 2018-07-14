#pragma once

#include <string>

//! This class is a container for a candidate word with a given confidence (the number of times
//! the word showed up during training).
class Candidate
{
public:

    //! Default Constructor
    Candidate();

    //! Copy Constructor
    //! @param[in] aCopy The Candidate you wish to copy
    Candidate(const Candidate & aCopy);

    //! Move Constructor
    //! @param[in] aCopy The Candidate you wish to move
    Candidate(const Candidate && aCopy);

    //! Copy assignment operator
    //! @param[in] aCopy The Candidate you wish to copy
    //! @return A copy of the Candidate.
    Candidate& operator=(const Candidate & aCopy);

    //! Move assignment operator
    //! @param[in] aCopy The Candidate you wish to move
    //! @return A copy of the Candidate.
    Candidate& operator=(const Candidate && aCopy);

    //! A unique constructor when give a confidence and a string.
    //! @param[in] Confidence The confidence (word count) of the given candidate.
    //! @param[in] Word       The candidate word.
    Candidate(
        int Confidence,
        const std::string & Word
    );

    //! Returns the confidence for this candidate.
    //! @return The confidence for this candidate.
    int getConfidence() const;

    //! Returns the word for this candidate.
    //! @return The word for this candidate.
    std::string getWord() const;

private:

    //! The number of times the word showed up during training.
    int Confidence_;

    //! The candidate word.
    std::string Word_;
};