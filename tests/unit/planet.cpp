#include <vector>
#include "../../lib/catch.hpp"
#include "../../src/configs/startup-config.hpp"
#include "../../src/planet/planet.hpp"
#include "../../src/coordinates.hpp"
#include "../../src/directions.hpp"

SCENARIO ("Planet ***")
{
    GIVEN ("Planet has valid attributes")
    {
        int surfaceWidth = 2;
        int surfaceHeight = 2;
        int obstacleNumber = 3;

        PlanetConfig planetConfig = { surfaceWidth, surfaceHeight, obstacleNumber };

        std::vector<std::vector<SurfaceSquare>> surface; //Tests not need this
        Planet planet = Planet(std::move(surface), planetConfig);

        WHEN("Coordinates north of north boundary")
        {
            Coordinates outOfBoundsCoordinates = { -1, 0 };
            Coordinates adjustedCoordinates = planet.adjustCoordinatesForSurfaceBoundaries(outOfBoundsCoordinates);

            THEN("Coordinates adjusted to opposite boundary")
            {
                Coordinates expectedAdjustedBoundary = { 1 , 0 };
                REQUIRE(adjustedCoordinates.fromTop == expectedAdjustedBoundary.fromTop);
                REQUIRE(adjustedCoordinates.fromLeft == expectedAdjustedBoundary.fromLeft);
            }
        }

        WHEN("Coordinates east of east boundary")
        {
            Coordinates outOfBoundsCoordinates = { 0, 2 };
            Coordinates adjustedCoordinates = planet.adjustCoordinatesForSurfaceBoundaries(outOfBoundsCoordinates);

            THEN("Coordinates adjusted to opposite boundary")
            {
                Coordinates expectedAdjustedBoundary = { 0 , 0 };
                REQUIRE(adjustedCoordinates.fromTop == expectedAdjustedBoundary.fromTop);
                REQUIRE(adjustedCoordinates.fromLeft == expectedAdjustedBoundary.fromLeft);
            }
        }

        WHEN("Coordinates south of south boundary")
        {
            Coordinates outOfBoundsCoordinates = { 2, 0 };
            Coordinates adjustedCoordinates = planet.adjustCoordinatesForSurfaceBoundaries(outOfBoundsCoordinates);

            THEN("Coordinates adjusted to opposite boundary")
            {
                Coordinates expectedAdjustedBoundary = { 0 , 0 };
                REQUIRE(adjustedCoordinates.fromTop == expectedAdjustedBoundary.fromTop);
                REQUIRE(adjustedCoordinates.fromLeft == expectedAdjustedBoundary.fromLeft);
            }
        }

        WHEN("Coordinates west of west boundary")
        {
            Coordinates outOfBoundsCoordinates = { 0, -1 };
            Coordinates adjustedCoordinates = planet.adjustCoordinatesForSurfaceBoundaries(outOfBoundsCoordinates);

            THEN("Coordinates adjusted to opposite boundary")
            {
                Coordinates expectedAdjustedBoundary = { 0 , 1 };
                REQUIRE(adjustedCoordinates.fromTop == expectedAdjustedBoundary.fromTop);
                REQUIRE(adjustedCoordinates.fromLeft == expectedAdjustedBoundary.fromLeft);
            }
        }

        WHEN("Coordinates within bounaries")
        {
            Coordinates outOfBoundsCoordinates = { 0 , 1 };
            Coordinates notAdjustedCoordinates = planet.adjustCoordinatesForSurfaceBoundaries(outOfBoundsCoordinates);

            THEN("Coordinates not adjusted")
            {
                Coordinates expectedAdjustedBoundary = { 0 , 1 };
                REQUIRE(notAdjustedCoordinates.fromTop == expectedAdjustedBoundary.fromTop);
                REQUIRE(notAdjustedCoordinates.fromLeft == expectedAdjustedBoundary.fromLeft);
            }
        }
    }
}
