class Player:
    def __init__(self, name):
        self.name = name
        self.score = 0
        self.loss_count = 0

    def increase_score(self):
        self.score += 1

    def increase_loss_cout(self):
        self.loss_count += 1

    def get_score(self):
        return self.score
