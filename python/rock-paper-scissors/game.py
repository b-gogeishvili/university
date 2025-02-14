from game_signs import Rock, Paper, Scissors

import random


class Game:
    def __init__(self, player):
        self.player = player
        self.player_choice = None
        self.computer_choice = None

        # Game is running -> True, False otherwise
        self.game_state = True

        # [Rock, Paper, Scissors] objects
        self.signs = {
            1: Rock(),
            2: Paper(),
            3: Scissors()
        }

    def _get_random_sign(self):
        """
        Returns random object from 'signs' dictionary:
        Rock, Paper or Scissors
        """
        return self.signs[random.choice([1, 2, 3])]

    def initialize_game(self, choice):
        self.player_choice = self.signs[choice]
        self.computer_choice = self._get_random_sign()

        print(f"{self.player.name}, you chose: {self.player_choice}")
        print(f"Computer chose: {self.computer_choice}")

    def is_running(self):
        return self.game_state

    def exit(self):
        self.game_state = False

    def evaluate(self):
        if self.player_choice.id == self.computer_choice.id:
            return "It's a Draw!!!"

        if self.player_choice.wins_over(self.computer_choice.id):
            self.player.increase_score()
            return f"You Won!!! Good job, {self.player.name}!"
        else:
            self.player.increase_loss_cout()
            return "You Lost!!! Try again."
