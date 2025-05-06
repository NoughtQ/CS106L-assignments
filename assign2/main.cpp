/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "Nought BQ"; // Don't forget to change this!

std::string get_initials(std::string name) {
  int pos = name.find(' ');
  std::string initials = std::string(1, name[0]) + std::string(1, name[pos + 1]);
  return initials;
}

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::unordered_set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::ifstream ifs("students.txt");
  std::unordered_set<std::string> applicants;

  if (ifs.is_open()) {
    std::string line;
    while (std::getline(ifs, line)) {
      applicants.insert(line);
    }
  }

  return applicants;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::unordered_set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::string initials = get_initials(name);
  // std::cout << initials << std::endl;
  std::queue<const std::string*> matching_names;

  for (const auto& student : students) {
    // std::cout << get_initials(student) << std::endl;
    if (get_initials(student) == initials)
      matching_names.push(&student);
      // std::cout << "haha" << std::endl;
  }
  // std::cout << "yes" << std::endl;

  return matching_names;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  std::string match_one = "", candidate;

  if (matches.empty()) {
    std::cout << "NO MATCHES FOUND." << std::endl;
  } else {
    match_one = *(matches.front());
    int max_len = match_one.length();
    matches.pop();
    while (!matches.empty()) {
      candidate = *(matches.front());
      if (candidate.length() > max_len) {
        match_one = candidate;
        max_len = candidate.length();
      }
      matches.pop();
    }
  }
  return match_one;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
