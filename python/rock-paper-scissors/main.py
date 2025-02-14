# Rock, Paper, Scissors

# WINS          LOSES
# -----------------------
# Paper    ->   Rock
# Rock     ->   Scissors
# Scissors ->   Paper

# Compare two different users to computer ?

from player import Player
from game import Game


def main():
    print("Rock, Paper, Scissors\n")
    name = input("Enter your name: ")
    print()

    player = Player(name)
    game = Game(player)

    while game.is_running():
        print("Please select your sign:")
        print("(1) Rock")
        print("(2) Paper")
        print("(3) Scissors")
        choice = int(input("=> "))
        print()

        game.initialize_game(choice)
        print(f"\n{game.evaluate()}")
        print()

        print(f"Your score is {player.score}")
        print(f"Computer score is {player.loss_count}")
        print()

        continue_game = input("Continue? (y/n) => ")
        if continue_game == "y":
            continue
        elif continue_game == "n":
            print("\nBye!")
            game.exit()
        else:
            print("\nInvalid input, exiting...")
            game.exit()


if __name__ == "__main__":
    main()
