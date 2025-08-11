
class DiningPhilosophers {
    mutex forks[5];  // one mutex per fork

public:
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) 
    {
        int leftFork = philosopher;           // fork on philosopher's left
        int rightFork = (philosopher + 1) % 5; // fork on right

        // Lock in a fixed order to avoid deadlock
        if (philosopher % 2 == 0) {
            forks[leftFork].lock();
            forks[rightFork].lock();
        } else {
            forks[rightFork].lock();
            forks[leftFork].lock();
        }

        // Actions
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();

        // Unlock both forks
        forks[leftFork].unlock();
        forks[rightFork].unlock();
    }
};
