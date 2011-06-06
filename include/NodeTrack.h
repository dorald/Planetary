/*
 *  NodeTrack.h
 *  Bloom
 *
 *  Created by Robert Hodgin on 1/21/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "Node.h"
#include "CinderIPod.h"

class NodeTrack : public Node
{
  public:
	NodeTrack( Node *parent, int index, const ci::Font &font, const ci::Font &smallFont, const ci::Surface &hiResSurfaces, const ci::Surface &loResSurfaces, const ci::Surface &noAlbumArt );
	void setData( ci::ipod::TrackRef track, ci::ipod::PlaylistRef album, const ci::Surface &albumArt );
    void initVertexArray();
	void updateAudioData( double currentPlayheadTime );
	void update( const ci::Matrix44f &mat, float param1, float param2 );
	void drawEclipseGlow();
	void drawPlanet( const ci::gl::Texture &tex );
	void drawClouds( const std::vector< ci::gl::Texture> &clouds );
	void drawOrbitRing( float pinchAlphaOffset, float camAlpha, const ci::gl::Texture &tex, GLfloat *ringVertsLowRes, GLfloat *ringTexLowRes, GLfloat *ringVertsHighRes, GLfloat *ringTexHighRes );
	void buildPlayheadProgressVertexArray();
	void drawPlayheadProgress( float pinchAlphaPer, float camAlpha, float pauseAlpha, const ci::gl::Texture &tex, const ci::gl::Texture &originTex );
	void drawAtmosphere( const ci::Vec2f &center, const ci::gl::Texture &tex, const ci::gl::Texture &directionalTex, float pinchAlphaPer );
	void findShadows( float camAlpha );
	void buildShadowVertexArray( ci::Vec3f p1, ci::Vec3f p2, ci::Vec3f p3, ci::Vec3f p4 );
	
	ci::Vec3f getStartRelPos(){ return mMatrix * mStartRelPos; }
	ci::Vec3f getRelPos(){ return mMatrix * mRelPos; }
	void setStartAngle();
	int getTrackNumber();

	string getName();
    uint64_t getId();
	bool isMostPlayed() { return mIsMostPlayed; }

	// TODO: should this be from a getData() function? or private?
	ci::ipod::TrackRef      mTrack;
	ci::ipod::PlaylistRef   mAlbum;	
	
private:
	float		mShadowPer;
	
	float		mAsciiPer;
	float		mEclipseStrength;
	float		mTrackLength;
	int			mPlayCount;
	float		mNormPlayCount;
	int			mStarRating;
	int			mNumTracks;
	ci::Vec3f	mStartPos, mTransStartPos, mStartRelPos;
	vector<ci::Vec3f> mOrbitPath;
	
	float		mPrevTime, mCurrentTime, mMyTime;
	double		mStartTime;
	double		mPlaybackTime;
	double		mPercentPlayed;
	
	bool		mHasClouds;
	bool		mIsMostPlayed;
	bool		mHasAlbumArt;
	bool		mHasCreatedAlbumArt;
	ci::gl::Texture mAlbumArtTex;
	ci::Surface	mAlbumArtSurface;
	
	float		mCloudLayerRadius;
	
	int			mTotalOrbitVertices;
    int			mPrevTotalOrbitVertices;
	GLfloat		*mOrbitVerts;
	GLfloat		*mOrbitTexCoords;
	GLfloat		*mOrbitColors;
	
	GLfloat		*mShadowVerts;
	GLfloat		*mShadowTexCoords;
};