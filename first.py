#coding utf 8

print("Trying out Python")
name = input("Present yourself: ")
print("You are going to regret entering my Lair,",name,"!")
answ = input("~Python prepares for a Fight!~\n Do you fight? {Y/N}")
 
 #PEP - 8 Look it up
# make stats a list, make the code shorter and make Encounter class
if answ == 'Y' :
	dp = 20 # damage points to deal to an enemy
	hp = 20 # your health points
	atc = 5 # your base attack
	blockp = 0 # your block points
	matc = 5
	
	print("		~You fight the Python~")
	
	while hp > 0 :
			
			fight = input(">Guard\nOR\n>Attack\n You choose: ")
			if fight == 'Guard' : 
				atc += 5
				blockp += 2
				print("~You gain 2 Defence points and 5 Attack points~")

			elif fight == 'Attack' :
				dp -= atc
				
				if blockp > 2 :
					blockp -= 2
				else : blockp = 0
					
				print("~You DEAL 5 Damage, but lose 2 Defence points~")
			else : 
				print("~You become Vulnerable~\nBe Careful!") 
				blockp -= 5
				
			if dp > 0 :
				print("		~Python's turn!~")
				hp = hp + blockp - matc
				print("~Python deals~")
				print(matc - blockp)
				
				if hp < 0 :
					print("~You are Defeated...~")
				else :
					print("Your hp:",hp,"/20	Enemy's hp:",dp,"/20") 
					
			else :
				print("		~You are Victorious!~")
				break

		
			
elif answ == 'N' :
	print("~You flee from the Dangers of this World and find Yourself unable to become a Hero~")
	print("~!BAD END!~")
else : 
	print("~Python Attacks You~\n~You TAKE Critical Damage~")
	print(">You Died<\n~!BAD END!~")
		
