ROCK = 1
PAPER = 2
SCISSORS = 3


class Rock:
    def __init__(self):
        self.id = ROCK
        self.loses_to = PAPER

    def wins_over(self, opponent_id):
        if opponent_id == self.loses_to:
            return False

        return True

    def __str__(self):
        return "Rock"


class Scissors:
    def __init__(self):
        self.id = SCISSORS
        self.loses_to = ROCK

    def wins_over(self, opponent_id):
        if opponent_id == self.loses_to:
            return False

        return True

    def __str__(self):
        return "Scissors"


class Paper:
    def __init__(self):
        self.id = PAPER
        self.loses_to = SCISSORS

    def wins_over(self, opponent_id):
        if opponent_id == self.loses_to:
            return False

        return True

    def __str__(self):
        return "Paper"
