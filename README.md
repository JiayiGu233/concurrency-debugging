# Concurrency Debugging Study

**C · pthread barriers · Memory debugging**

A thirteen-thread C coordination program exploring lock ordering, barriers and memory lifetime.

## Quick start

```text
make
./bin/timewar
valgrind --leak-check=full --error-exitcode=1 ./bin/timewar
valgrind --tool=helgrind --error-exitcode=1 ./bin/timewar
```

## Design

Workers synchronize at a barrier and combine calculations through shared state protected by mutexes. The source demonstrates fixes to the supplied concurrent program.

## Scope and validation

Linux is required for pthread barriers. Valgrind/Helgrind have not been run in this macOS preparation environment; a success message alone is not proof of race freedom.

See [VALIDATION.md](VALIDATION.md) for checks run against this edition. Source background and authorship are recorded in [PROVENANCE.md](PROVENANCE.md).
