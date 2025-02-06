import pyautogui, time, os


def random(bit):
    '''
    Random function accepts one parameter: *bit*
    This represents maximum number of bits our random number will have.
    In order to get 32bit Random Number, we pass a number 32 as an argument.
    '''

    # This is used to display number in binary.
    bit_format = f"0{bit}b"

    # Mouse position is (X, Y) point on our display.
    x, y = pyautogui.position()
    
    # Decided to modify the given values by using bitwise OR between X and Y values. 
    # Also used bitwise AND with current time for more randomness.
    rand_seed = (int(x) | int(y)) & time.time_ns()
    
    # Decided to shrink the number to make it between 0.0 and 1.0
    # For example:
    #   If we got 1234 from the above operation, 
    #   with this command we will get 0.1234
    rational_num = (rand_seed % 1000) / 1000
    
    # Need to multiply the result by 2^bit - 1
    # bit = number of bits passed as an argument
    random = round(rational_num * (2**bit - 1))
    
    # We can shift bits to only generate random number with specific bits
    # For example:
    #   We want to generate 32 bit Random Number.
    #   If our generated random number's bit length is 30,
    #   we can shift bits to the left by 2
    #   (32 - 30) = 2
    bits_left = bit - random.bit_length()
    return random << bits_left, bit_format


count = 1
while True: 
    os.system("clear") # Not working on Windows

    try:
        print(f"<-----Numbers Generated: {count}-----> \n")
        
        rand, bit_format = random(32)

        print(f"Decimal: {rand}")
        print(f"Binary: {format(rand, bit_format)}")
        print(f"Bit Length: {rand.bit_length()}\n")
        
        print("Ctrl+C to exit\n")

        count += 1
        time.sleep(2)


    except KeyboardInterrupt:
        print("\nExiting...")
        break
