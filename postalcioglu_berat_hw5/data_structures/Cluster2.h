#pragma once

#include <string>
#include <vector>
#include "Typedefs.h"

struct node_branch
{
public:
  double distance;
  node_branch *next_col;
  node_branch *next_row;
  node_branch() : distance(0.0), next_col(NULL), next_row(NULL) {}
};

struct cluster
{
public:
  cluster *prev;
  cluster *next;
  node_branch *row;
  node_branch *column;
  std::string name;
  int num_of_nodes;
  cluster() : prev(NULL), next(NULL), row(NULL), column(NULL), num_of_nodes(0) {}
};

void run_upgma(cluster *&fc, cluster *&lc);

std::vector<double> run_formula(cluster *c1, cluster *c2, std::vector<double> c1_vals, std::vector<double> v2_vals);

void insert(cluster *&fc, cluster *&lc, const std::string &name);

void remove(cluster *&fc, cluster *&lc, cluster *c_no_remove);

void find_min_distance(cluster *fc, cluster *&c1, cluster *&c2);

void merge_clusters(cluster *&fc, cluster *&lc, cluster *&c1, cluster *&c2, std::vector<double> vals, double val);
