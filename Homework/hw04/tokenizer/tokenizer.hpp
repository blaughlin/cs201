// tokenizer.hpp
// Created by Bernard Laughlin on 10/1/21.
// Header file for tokenizer

#include <iostream>
#ifndef TOKENIZER_TOKENIZER_HPP
#define TOKENIZER_TOKENIZER_HPP

bool ReadLine(std::string & str);

unsigned StringToTokensWS(const std::string &input, std::vector<std::string> &tokens);

void AnalyzeTokens(const std::vector<std::string> &tokens);

#endif //TOKENIZER_TOKENIZER_HPP
