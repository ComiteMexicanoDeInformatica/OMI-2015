class program {
    void bump() {
        while (frontIsClear)
            move();
    }
 
    void turn(n) {
        iterate(n)
        turnleft();
    }
 
    void turnright() {
        turn(3);
    }
 
    void north() {
        while (notFacingNorth)
            turnleft();
    }
 
    void east() {
        while (notFacingEast)
            turnleft();
    }
 
    void west() {
        while (notFacingWest) {
            turnleft();
        }
    }
 
    void south() {
        while (notFacingSouth)
            turnleft();
    }
 
    void put(n) {
        iterate(n)
        	putbeeper();
    }
    
    void take(n) {
        iterate(n)
        	pickbeeper();
    }
 
    void back() {
        turn(2);
        move();
        turn(2);
    }
 
    void oneStep() {
        move();
        if (nextToABeeper && frontIsClear)
            return ();
        back();
        turnleft();
        move();
        if (nextToABeeper && frontIsClear)
            return ();
        back();
        turn(2);
        move();
    }
 
    void findPath() {
    	west();
        bump();
        while (iszero(0)) {
            south();
            bump();
            east();
            move();
            north();
            while (notNextToABeeper && frontIsClear)
                move();
            if (nextToABeeper)
                return ();
        }
    }
 
    void getNAndMove(n) {
        if (nextToABeeper) {
            pickbeeper();
            getNAndMove(succ(n));
        } else {
            put(pred(n));
            findPath();
            iterate(n)
            oneStep();
        }
    }
    
    void init4(n) {
        if (frontIsClear) {
            move();
            init4(n);
            move();
        } else {
            put(n);
            east();
        }
    }
 
    void init3(n) {
        if (notFacingWest) {
            turnleft();
            init3(n);
            turnright();
        } else {
            init4(n);
            west();
        }
    }
 
    void init2(n) {
        if (frontIsClear) {
            move();
            init2(n);
            move();
        } else {
            init3(n);
            turn(2);
        }
    }
 
    void init1(n) {
        if (notFacingSouth) {
            turnleft();
            init1(n);
            turnright();
        } else {
            init2(n);
            south();
        }
    }
 
    void init(n) {
        if (nextToABeeper) {
            pickbeeper();
            init(succ(n));
        } else {
            put(n);
            init1(n);
        }
    }
 
    void goAndReturn4(n) {
        if (frontIsClear) {
            move();
            goAndReturn4(n);
            move();
        } else {
            put(n);
            north();
            max(0);
            move();
            move();
            if (notNextToABeeper){
            	south();
                move();
            	copyAnswer(0);
                turnoff();
            }
            pickbeeper();
            turn(2);
            move();
            move();
            east();
        }
    }
 
    void goAndReturn3(n) {
        if (notFacingWest) {
            turnleft();
            goAndReturn3(n);
            turnright();
        } else {
            goAndReturn4(n);
            west();
        }
    }
 
    void goAndReturn2(n) {
        if (frontIsClear) {
            move();
            goAndReturn2(n);
            move();
        } else {
            goAndReturn3(n);
            turn(2);
        }
    }
 
    void goAndReturn1(n) {
        if (notFacingSouth) {
            turnleft();
            goAndReturn1(n);
            turnright();
        } else {
            goAndReturn2(n);
            south();
        }
    }
 
    void addToCounter(n) {
        if (nextToABeeper) {
            pickbeeper();
            addToCounter(succ(n));
        } else {
            put(n);
            goAndReturn1(n);
        }
    }
    
    void goAndSubtract4(n) {
        if (frontIsClear) {
            move();
            goAndSubtract4(n);
            move();
        } else {
            take(n);
            turn(2);
        }
    }
 
    void goAndSubtract3(n) {
        if (notFacingWest) {
            turnleft();
            goAndSubtract3(n);
            turnright();
        } else {
            goAndSubtract4(n);
            west();
        }
    }
 
    void goAndSubtract2(n) {
        if (frontIsClear) {
            move();
            goAndSubtract2(n);
            move();
        } else {
            goAndSubtract3(n);
            turn(2);
        }
    }
 
    void goAndSubtract1(n) {
        if (notFacingSouth) {
            turnleft();
            goAndSubtract1(n);
            turnright();
        } else {
            goAndSubtract2(n);
            south();
        }
    }
 
    void subtractFromCounter(n) {
        if (nextToABeeper) {
            pickbeeper();
            subtractFromCounter(succ(n));
        } else {
            put(n);
            goAndSubtract1(n);
        }
    }
 
    void collect(k) {
        if (!iszero(k)) {
            init(0);
            oneStep();
            collect(pred(k));
        }
    }
 
    void max2(n) {
        if (!iszero(n) && nextToABeeper) {
            pickbeeper();
            max2(pred(n));
            putbeeper();
        } else {
            put(n);
        }
    }
 
    void max(n) {
        if (nextToABeeper) {
            pickbeeper();
            max(succ(n));
            putbeeper();
        } else {
            move();
            max2(n);
            back();
        }
    }
    
    void go(k){
    	while (iszero(0)){
          subtractFromCounter(0);
          iterate (k)
            oneStep();
          addToCounter(0);
          turn(2);
          iterate (pred(k))
              oneStep();
          turn(2);
       }
    }
 
    void getK(k) {
        if (nextToABeeper) {
            pickbeeper();
            getK(succ(k));
        } else {
            move();
            move();
            findPath();
            collect(k);
            turn(2);
            iterate (k)
            	oneStep();
            turn(2);
            go(k);
        }
    }
 
    void copyAnswer(n) {
        if (nextToABeeper) {
            pickbeeper();
            copyAnswer(succ(n));
        } else {
            put(n);
            south();
            move();
            while (nextToABeeper) pickbeeper();
            put(n);
        }
    }
 
    program() {
        south();
        bump();
        west();
        bump();
        north();
        move();
        move();
        put(50);
        south();
        bump();
        north();
        getK(0);
    }
}