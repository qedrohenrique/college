from collections import deque



class State:


# Missionaires and Cannibals - integers
# boatSide				  	 - char
# parent 					 - State



	def __init__(self, leftMis, leftCan, rightMis, rightCan, boatSide, parent = None):
		self.leftMis = leftMis
		self.leftCan = leftCan
		self.rightMis = rightMis
		self.rightCan = rightCan
		self.boatSide = boatSide
		self.parent = parent

	def isFinalState(self):
		return (self.leftMis == 0
				  and self.leftCan == 0 
				  and self.rightMis == 3 
				  and self.rightCan == 3)

	def isValidState(self):
		return 	(self.leftMis == 0 or self.rightMis == 0) \
				or ((self.leftMis >= self.leftCan) \
				and (self.rightMis >= self.rightCan) \
				and (self.leftMis >= 0 and self.rightMis >= 0) \
				and (self.leftCan >= 0 and self.rightCan >= 0))

	def possibleStates(currState):
		successors = []
		possibleMoves = [(2,0), (1,0), (1,1), (0,1), (0,2)]

		if currState.boatSide == "L":
			for move in possibleMoves:
				newState = State(currState.leftMis - move[0], currState.leftCan - move[1],
								 currState.rightMis + move[0], currState.rightCan + move[1], "R", currState)
				if newState.isValidState():
					successors.append(newState)
		else:
			for move in possibleMoves:
				newState = State(currState.leftMis + move[0], currState.leftCan + move[1],
								 currState.rightMis - move[0], currState.rightCan - move[1], "L", currState)
				if newState.isValidState():
					successors.append(newState)

		return successors

	def BFS(self):
		initalState = self

		if initalState.isFinalState():
			return initalState

		visitedStates = []
		q = deque([])
		q.append(initalState)

		while len(q):
			state = q.popleft()

			if state.isFinalState():
				return state

			visitedStates.append(state)

			kidsStates = State.possibleStates(state)

			for kState in kidsStates:
				if (kState not in visitedStates) and (kState not in q):
					q.append(kState)

		return None

	def backtrackStates(self):
		currState = self
		backtrackList = list()
		while currState.parent:
			backtrackList.append(currState)
			currState = currState.parent
		return backtrackList
			


if __name__ == "__main__":
	
	dummyState = State(3,3,0,0,"L")
	a = dummyState.BFS()
	steps = a.backtrackStates()

	while steps:
	 popState = steps.pop()
	 print(popState.leftMis, popState.leftCan, popState.rightMis, popState.rightCan)