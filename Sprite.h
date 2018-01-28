
struct iPoint2D{
    
       iPoint2D(int x, int y) : X(x), Y(y){}
	int   X,
		  Y;
};

struct iPoint3D{
    
    iPoint3D(int x, int y, int z) : X(x), Y(y), Z(z){}
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
        struct{
	iPoint2D POSITION;
    iPoint2D SIZE;};
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


	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    