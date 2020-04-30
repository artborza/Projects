function workout() {
    let gym = 'Gym A';
    const gymStatuses = { 'Gym A': 'open', 'Gym B': 'closed' };
    for (let gym in gymStatuses) {
        console.log(gym + ' is ' + gymStatuses[gym]);
    }
}