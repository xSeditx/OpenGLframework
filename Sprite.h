
struct iPoint2D{
	int   X,
		  Y;
};

struct iPoint3D{
	int   X,
		  Y,
		  Z;
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                      BASE SPRITE CLASS                                                                                                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Sprite{
public:
	union Rect{
	iPoint2D POSITION;
	iPoint2D SIZE;
	};

	virtual void RENDER();

protected:
private:

};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                      ANIMATED SPRITE CLASS                                                                                                                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class AniSprite: public Sprite{
public:

protected:
private:
	virtual void RENDER();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                      STATIC TILE SPRITES                                                                                                                                               //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class StaticSprite: public Sprite{
public:

protected:
private:
	virtual void RENDER();
}


	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    