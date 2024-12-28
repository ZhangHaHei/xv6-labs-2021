#ifndef SPINLOCK_H    // 如果没有定义 SPINLOCK_H
#define SPINLOCK_H    // 定义 SPINLOCK_H，防止再次包含

// Mutual exclusion lock.
struct spinlock {
  uint locked;       // Is the lock held?

  // For debugging:
  char *name;        // Name of lock.
  struct cpu *cpu;   // The cpu holding the lock.
};


#endif  // 结束宏定义


