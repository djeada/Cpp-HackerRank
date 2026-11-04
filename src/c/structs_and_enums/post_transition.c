#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct package {
  char *id;
  int weight;
} package;

typedef struct post_office {
  int min_weight;
  int max_weight;
  package *packages;
  int packages_count;
} post_office;

typedef struct town {
  char *name;
  post_office *offices;
  int offices_count;
} town;

void print_all_packages(town t) {
  printf("%s:\n", t.name);
  for (int i = 0; i < t.offices_count; ++i) {
    const post_office *office = &t.offices[i];
    printf("\t%d:\n", i);
    for (int j = 0; j < office->packages_count; ++j) {
      printf("\t\t%s\n", office->packages[j].id);
    }
  }
}

static bool accepts(const post_office *office, int weight) {
  return weight >= office->min_weight && weight <= office->max_weight;
}

void send_all_acceptable_packages(town *source, int source_office_index,
                                  town *target, int target_office_index) {
  post_office *from = &source->offices[source_office_index];
  post_office *to = &target->offices[target_office_index];
  if (from == to) {
    return;
  }

  int accepted = 0;
  for (int i = 0; i < from->packages_count; ++i) {
    if (accepts(to, from->packages[i].weight)) {
      ++accepted;
    }
  }
  if (accepted == 0) {
    return;
  }

  const size_t count = (size_t)to->packages_count + (size_t)accepted;
  package *grown = realloc(to->packages, count * sizeof *grown);
  if (grown == NULL) {
    exit(EXIT_FAILURE);
  }
  to->packages = grown;

  // Append accepted packages and compact rejected ones in their original order.
  int kept = 0;
  for (int i = 0; i < from->packages_count; ++i) {
    const package current = from->packages[i];
    if (accepts(to, current.weight)) {
      to->packages[to->packages_count++] = current;
    } else {
      from->packages[kept++] = current;
    }
  }
  from->packages_count = kept;
}

town town_with_most_packages(town *towns, int towns_count) {
  int best = 0;
  int most = -1;
  for (int i = 0; i < towns_count; ++i) {
    int count = 0;
    for (int j = 0; j < towns[i].offices_count; ++j) {
      count += towns[i].offices[j].packages_count;
    }
    if (count > most) {
      most = count;
      best = i;
    }
  }
  return towns[best];
}

town *find_town(town *towns, int towns_count, char *name) {
  for (int i = 0; i < towns_count; ++i) {
    if (strcmp(towns[i].name, name) == 0) {
      return &towns[i];
    }
  }
  return NULL;
}

static void *allocate(size_t count, size_t size) {
  void *data = calloc(count, size);
  if (data == NULL && count != 0) {
    exit(EXIT_FAILURE);
  }
  return data;
}

static int read_int(void) {
  int value;
  if (scanf("%d", &value) != 1) {
    exit(EXIT_FAILURE);
  }
  return value;
}

static char *read_name(void) {
  char buffer[64];
  if (scanf("%63s", buffer) != 1) {
    exit(EXIT_FAILURE);
  }
  const size_t size = strlen(buffer) + 1;
  char *name = allocate(size, sizeof *name);
  return memcpy(name, buffer, size);
}

static void read_offices(town *t) {
  t->offices_count = read_int();
  t->offices = allocate((size_t)t->offices_count, sizeof *t->offices);
  for (int i = 0; i < t->offices_count; ++i) {
    post_office *office = &t->offices[i];
    office->packages_count = read_int();
    office->min_weight = read_int();
    office->max_weight = read_int();
    office->packages =
        allocate((size_t)office->packages_count, sizeof *office->packages);
    for (int j = 0; j < office->packages_count; ++j) {
      office->packages[j].id = read_name();
      office->packages[j].weight = read_int();
    }
  }
}

static void free_towns(town *towns, int count) {
  for (int i = 0; i < count; ++i) {
    town *t = &towns[i];
    for (int j = 0; j < t->offices_count; ++j) {
      post_office *office = &t->offices[j];
      for (int k = 0; k < office->packages_count; ++k) {
        free(office->packages[k].id);
      }
      free(office->packages);
    }
    free(t->offices);
    free(t->name);
  }
  free(towns);
}

int main(void) {
  const int town_count = read_int();
  town *towns = allocate((size_t)town_count, sizeof *towns);
  for (int i = 0; i < town_count; ++i) {
    towns[i].name = read_name();
    read_offices(&towns[i]);
  }

  const int queries = read_int();
  for (int i = 0; i < queries; ++i) {
    const int type = read_int();
    if (type == 3) {
      printf("Town with the most number of packages is %s\n",
             town_with_most_packages(towns, town_count).name);
      continue;
    }

    char name[64];
    if (scanf("%63s", name) != 1) {
      exit(EXIT_FAILURE);
    }
    town *source = find_town(towns, town_count, name);
    if (type == 1) {
      print_all_packages(*source);
    } else {
      const int source_index = read_int();
      if (scanf("%63s", name) != 1) {
        exit(EXIT_FAILURE);
      }
      town *target = find_town(towns, town_count, name);
      const int target_index = read_int();
      send_all_acceptable_packages(source, source_index, target, target_index);
    }
  }

  free_towns(towns, town_count);
  return 0;
}
