/*
 * Only give sleepers 50% of their service deficit. This allows
 * them to run sooner, but does not allow tons of sleepers to
 * rip the spread apart.
 */
SCHED_FEAT(GENTLE_FAIR_SLEEPERS, 1)

/*
 * Place new tasks ahead so that they do not starve already running
 * tasks
 */
SCHED_FEAT(START_DEBIT, 1)

/*
 * Should wakeups try to preempt running tasks.
 */
SCHED_FEAT(WAKEUP_PREEMPT, 1)

/*
 * Based on load and program behaviour, see if it makes sense to place
 * a newly woken task on the same cpu as the task that woke it --
 * improve cache locality. Typically used with SYNC wakeups as
 * generated by pipes and the like, see also SYNC_WAKEUPS.
 */
SCHED_FEAT(AFFINE_WAKEUPS, 1)

/*
 * Prefer to schedule the task we woke last (assuming it failed
 * wakeup-preemption), since its likely going to consume data we
 * touched, increases cache locality.
 */
SCHED_FEAT(NEXT_BUDDY, 0)

/*
 * Prefer to schedule the task that ran last (when we did
 * wake-preempt) as that likely will touch the same data, increases
 * cache locality.
 */
SCHED_FEAT(LAST_BUDDY, 1)

/*
 * Consider buddies to be cache hot, decreases the likelyness of a
 * cache buddy being migrated away, increases cache locality.
 */
SCHED_FEAT(CACHE_HOT_BUDDY, 1)

/*
 * Use arch dependent cpu power functions
 */
SCHED_FEAT(ARCH_POWER, 0)

SCHED_FEAT(HRTICK, 0)
SCHED_FEAT(DOUBLE_TICK, 0)
SCHED_FEAT(LB_BIAS, 1)
SCHED_FEAT(LB_SHARES_UPDATE, 1)
SCHED_FEAT(ASYM_EFF_LOAD, 1)

/*
 * Spin-wait on mutex acquisition when the mutex owner is running on
 * another cpu -- assumes that when the owner is running, it will soon
 * release the lock. Decreases scheduling overhead.
 */
SCHED_FEAT(OWNER_SPIN, 1)

/*
 * Decrement CPU power based on irq activity
 */
SCHED_FEAT(NONIRQ_POWER, 1)
