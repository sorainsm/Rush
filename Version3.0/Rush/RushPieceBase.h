#pragma once

#include "C4Controller.h"
#include "C4World.h"
#include "C4Configuration.h"

using namespace C4;

namespace Rush
{
	enum ControllerType
	{
		//Classic mode
		kControllerPawn = 'pawn',
		kControllerKnight = 'kngt',
		kControllerBishop = 'bisp',
		kControllerRook = 'rook',
		kControllerQueen = 'quen',
		kControllerKing = 'king',
		//Battleship mode
		kControllerBattleship = 'bshp',
		kControllerCarrier = 'carr',
		kControllerDestroyer = 'dest',
		kControllerSalvage = 'salv',
		kControllerTorpedo = 'torp'
	};

	enum ModelTypes
	{
		//Classic mode
		kModelPawn = 'pawn',
		kModelKnight = 'kngt',
		kModelBishop = 'bisp',
		kModelRook = 'rook',
		kModelQueen = 'quen',
		kModelKing = 'king',
		//Battleship mode
		kModelBattleship = 'bshp',
		kModelCarrier = 'carr',
		kModelDestroyer = 'dest',
		kModelSalvage = 'salv',
		kModelTorpedo = 'torp'
	};

	class RushPieceController : public Controller
	{
		private:
			RushPieceController(const RushPieceController &pieceController);
			Controller *Replicate(void) const;

			DiffuseAttribute		*diffuse;
			EmissionAttribute		*emission;
			MaterialObject			*matObject;

			bool					selected;
			
			Point3D					wayPoint;

			float					curRotation;
			float					reqRotation;

			unsigned_int32			playerControlled;
			

			void MovePiece(Model *model, float dt);

		public:
			RushPieceController();
			RushPieceController(Rush::ControllerType type);
			~RushPieceController();

			void SetSelected(bool select);
			bool IsSelected();

			void SetPlayerControlled(unsigned_int32 state)
			{
				playerControlled = state;
			}
			bool IsPlayerControlled()
			{
				if (playerControlled != 0)
				{
					return (true);
				}
				else
				{
					return (false);
				};
			}
						
			Point3D GetWayPoint()
			{
				return (wayPoint);
			}
			void SetWayPoint(Point3D point)
			{
				wayPoint = point;
			}
			
			static bool ValidNode(const Node *node);

			int32 GetSettingCount(void) const;
			Setting *GetSetting(int32 index) const;
			void SetSetting(const Setting *setting);

			void Pack(Packer &data, unsigned_int32 packFlags) const;
			void Unpack(Unpacker &data, unsigned_int32 unpackFlags);
			bool UnpackChunk(const ChunkHeader *header, Unpacker &data, unsigned_int32 unpackFlags);

			void Preprocess(void);

			void Move(void);
			void Travel(void);
	};
}