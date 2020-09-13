''' A simple Car Game for fun ( code written in Python 3) '''

'''
    * This is a simple car game
    * It can be play by writing command
    * It is written for self improvement
    * It is written for fun purpose
'''

command = ""
started = False
running = False
lane = 1
score = 0
counter = 1
print("""
<< start - To start the car    >>
<< run   - To speed uo the car >>
<< break - To slow the car     >>
<< stop  - To stop the car     >>
<< right - To go right         >>
<< left  - To go left          >>
<< quit  - To end the game     >>""")
while True:
    command = input("Command -> ").lower()

    if command == "start":
        if started:
            print("<< Car is already started... >>")
            score -= counter
        else:
            started = True
            print("<< Car Started.. Ready to go! >>")
            score += (3 * counter)

    elif command == "run":
        if started:
            if running:
                print("<< Speed  up... >>")
                counter += 1
            else:
                running = True
                print("<< Car start running... >>")
                score += (2 * counter)
        else:
            print("<< Car is not started... >>")

    elif command == "break":
        if started:
            if not running:
                print("<< Car is nor running... >>")
                counter = 1
            else:
                running = False
                print("<< Car stop Running.. >>")
                counter -= 1
        else:
            print("<< Car is not started... >>")

    elif command == "right":
        if started:
            if running:
                if lane == 1:
                    lane = 0
                    print("<< Car is in right lane... >>")
                    score += (1 * counter)
                elif lane == 2:
                    lane = 1
                    print("<< Car is in center lane... >>")
                    score += (1 * counter)
                else:
                    print("""<< Car crashed!!! >>
        
    <<  GAME OVER   >>""")
                    break
            else:
                print("<< Car is not running... >>")
        else:
            print("<< Car is not started... >>")

    elif command == "left":
        if started:
            if running:
                if lane == 1:
                    lane = 2
                    print("<< Car is in left lane... >>")
                    score += (1 * counter)
                elif lane == 0:
                    lane = 1
                    print("<< Car is in center lane... >>")
                    score += (1 * counter)
                else:
                    print("""<< Car crashed!!! >>

    <<  GAME OVER   >>""")
                    break
            else:
                print("<< Car is not running... >>")
        else:
            print("<< Car is not started... >>")

    elif command == "stop":
        if not started:
            print("<< Car is already stopped... >>")
            score -= 1
        else:
             started = False
             running = False
             print("<< Car stopped...>>")
             counter = 1

    elif command == "help":
        print("""<< start - To start the car    >>
<< run   - To speed uo the car >>
<< break - To slow the car     >>
<< stop  - To stop the car     >>
<< right - To go right         >>
<< left  - To go left          >>
<< quit  - To end the game     >>""")

    elif command == "quit":
        print(f"    <<  YOU STOP PLAYING THE GAME   >>")
        score += 5
        break

    else:
        print("<< Sorry, I don't understand that... >>")

print(f"    <<  SCORE: {score}  >>")