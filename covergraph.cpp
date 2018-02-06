//
// Created by Tafseer Ahmed on 2/5/2018.
//
#include <iostream>
#include <vector>
#include <utility>
#include "covergraph.h"

CoverGraph::CoverGraph(unsigned int size) {
    N = size;
    std::cout << "Enter labels for each node \n";
    std::string label;
    for (int i = 0; i < N; i++) {
        std::cout << "\n Node " << i << " :";
        std::cin >> label;
        P.push_back(make_pair(i, label));
    }
    E.resize(N);
    std::cout << "Enter Adjacency list E, '-1' terminates list \n";
    for (int i = 0; i < N; i++) {
        int x;
        std::cout << "Add edges for Node " << P[i].second << " (" << i << "): ";
        std::cin >> x;
        while (x != -1) {
            E[i].push_back(x);
            std::cin >> x;
        }
    }
}

void CoverGraph::INIT() {
    M.resize(N);
    V.resize(N);
    fill(V.begin(), V.end(), 0);
    for (int i = 0; i < N; i++) {
        M[i].resize(N);
        for (int j = 0; j < N; j++) {
            M[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < E[i].size(); j++) {
            int k = E[i][j];
            M[i][k] = 1;
            V[k]++;
        }
    }
    std::cout << "Data Structure successfully initialized!\n";
}

void CoverGraph::DelMin() {
    int x;
    for (int i = 0; i < N; i++) {
        std::cout << i << " - " << P[i].second;
        if (V[i] == 0) std::cout << " (Minimal)";
        else if (V[i] < 0) std::cout << "(Deleted)";
        std::cout << std::endl;
    }
    std::cout << "Enter minimal element's node number to be deleted: ";
    std::cin >> x;
    if (V[x] != 0) std::cout << "Element is not a Minimal element!\n";
    else {
        V[x]--;
        for (int j = 0; j < E[x].size(); j++) {
            int k = E[x][j];
            M[x][k] = 0;
            V[k]--;
        }
    }
    std::cout << "Minimal element " << P[x].second << " has been deleted successfully! \n";
}

void CoverGraph::ListMin() {
    std::cout << "List of Minimal elements is\n";
    for (int i = 0; i < N; i++) {
        if (V[i] == 0) std::cout << i << " - " << P[i].second << std::endl;
    }
    std::cout << std::endl;
}
