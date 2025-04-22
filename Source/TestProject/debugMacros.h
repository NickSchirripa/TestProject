#pragma once



#define DrawSphere(location, color) if (GetWorld()) DrawDebugSphere(GetWorld(), location, 25.f, 12, FColor::color, true);
#define DrawSphereSingleFrame(location, color)if (GetWorld()) DrawDebugSphere(GetWorld(), location, 25.f, 12, FColor::color, false, -1.f);
#define DrawLine(startLine, endLine) if(GetWorld()) DrawDebugLine(GetWorld(), startLine, startLine + endLine,  FColor::Blue, true, -1.f, 0, 1.f);
#define DrawLineSingleFrame(startline, endline) if(GetWorld()) DrawDebugLine(GetWorld(), startLine, startLine + endLine,  FColor::Blue, false, -1.f, 0, 1.f);
#define DrawPoint(actorLocation, forVec)	if (GetWorld())DrawDebugPoint(GetWorld(), actorLocation + forVec , 20.f, FColor::Emerald, true);
#define DrawPointSingleFrame(actorlocation, forVec)if (GetWorld())DrawDebugPoint(GetWorld(), actorLocation + forVec , 20.f, FColor::Emerald, false, -1.f);
#define DrawVector(startLocation, endLocation)if(GetWorld())\
	{\
		DrawDebugLine(GetWorld(), startLocation, endLocation,  FColor::Blue, true, -1.f, 0, 1.f);\
		DrawDebugPoint(GetWorld(),endLocation, 20.f, FColor::Emerald, true);\
}

#define DrawVectorSingleFrame(startLocation, endLocation)if(GetWorld())\
	{\
		DrawDebugLine(GetWorld(), startLocation, endLocation,  FColor::Blue, false, -1.f, 0, 1.f);\
		DrawDebugPoint(GetWorld(),endLocation, 20.f, FColor::Emerald, false, -1.f);\
}


