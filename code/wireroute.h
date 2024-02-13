/**
 * Parallel VLSI Wire Routing via OpenMP
 * Name 1(andrew_id 1), Name 2(andrew_id 2)
 */

#ifndef __WIREOPT_H__
#define __WIREOPT_H__

#include <omp.h>
#include <cstdint>
#include <vector>

#define MAX_PTS_PER_WIRE 4
#define COST_REPORT_DEPTH 10

struct validate_wire_t {
  uint8_t num_pts;
  struct {
    uint16_t x;
    uint16_t y;
  } p[MAX_PTS_PER_WIRE];
  validate_wire_t &cleanup(void);
};

struct Wire {
  /* Define the data structure for wire here. */ 
  int start_x, start_y, end_x, end_y, bend1_x, bend1_y;
  validate_wire_t to_validate_format(void) const;
};


struct wr_checker {
  std::vector<Wire> wires;
  std::vector<std::vector<int>> occupancies;
  const int nwires;
  const int dim_x;
  const int dim_y;
  wr_checker(std::vector<Wire> &wires, std::vector<std::vector<int>> &occupancies, 
    const int nwires, const int dim_x, const int dim_y) 
  : wires(wires), occupancies(occupancies), nwires(nwires), dim_x(dim_x), dim_y(dim_y) {}
  void validate() const;
};

const char *get_option_string(const char *option_name,
                              const char *default_value);
int get_option_int(const char *option_name, int default_value);
float get_option_float(const char *option_name, float default_value);

#endif
