# RouteSearchProblem

## Description

An algorithm for finding the total value when tracing a route that is the minimum total value among multiple routes.p

## Example

### Input

```
567
133
502
```

### Output

The total value in the case of following the route with the minimum total value is output to the standard output.

```
11
```

### All routes and total value

Total route and total value in the above case.

```
route: 5 -> 6 -> 7 -> 3 -> 2, sum: 23
route: 5 -> 6 -> 3 -> 3 -> 2, sum: 19
route: 5 -> 6 -> 3 -> 0 -> 2, sum: 16
route: 5 -> 1 -> 3 -> 3 -> 2, sum: 14
route: 5 -> 1 -> 3 -> 0 -> 2, sum: 11 ★
route: 5 -> 1 -> 5 -> 0 -> 2, sum: 13
```
