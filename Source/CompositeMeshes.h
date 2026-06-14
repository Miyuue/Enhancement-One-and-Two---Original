#pragma once

#include "CompositeMeshObject.h"
#include "ShapeMeshes.h"

// This is a namesapce allowing for the construction and external referencing of CompositeMeshObjects
// Author: Samuel Williamson

namespace CompositeMeshes
{
	// for testing/example
	static CompositeMeshObject Wizard(Transform& compositeTransform)
	{
		CompositeMeshObject wizard;

		// Hat
		// -----------------------------------------------------------
		MeshObject hat;
		hat.mesh = CONE;

		// Set the transform, color, and mesh
		hat.transform.Reset(); // set to defaults (less stuff to set manually)
		hat.transform.positionXYZ = glm::vec3(0.0f, 0.9f, 0.0f);
		hat.transform.scaleXYZ = glm::vec3(0.5f, 2.0f, 0.5f);

		hat.color.Reset(); // set to defaults (less stuff to set manually)
		hat.color.g = 0.0f;

		wizard.AddChild(hat); // Add to composite
		// -----------------------------------------------------------

		// Head
		// -----------------------------------------------------------
		MeshObject head;
		head.mesh = SPHERE;

		// Set the transform, color, and mesh
		head.transform.Reset(); // set to defaults

		head.color.Reset(); // set to defaults

		wizard.AddChild(head); // Add to composite
		// -----------------------------------------------------------

		wizard.SetTransform(compositeTransform); // This sets the children's transforms relative to the composite's
		return wizard;
	}

	static CompositeMeshObject Table(Transform& compositeTransform)
	{
		CompositeMeshObject table;

		// Table-top
		// -----------------------------------------------------------
		MeshObject tableTop;
		tableTop.mesh = BOX;

		tableTop.transform.Reset();
		tableTop.transform.scaleXYZ = glm::vec3(10.0f, 0.55f, 5.0f);

		tableTop.texture = "tabletop";
		tableTop.material = "wood";

		table.AddChild(tableTop);
		// -----------------------------------------------------------

		// Left Table Legs
		// -----------------------------------------------------------
		MeshObject leftTableLeg0;
		leftTableLeg0.mesh = BOX;

		leftTableLeg0.transform.Reset();
		leftTableLeg0.transform.positionXYZ = glm::vec3(-4.5001f, -1.5f, 0.0f); // 4.5001f stops "z-fighting"
		leftTableLeg0.transform.scaleXYZ = glm::vec3(0.25f, 3.5f, 0.8f);
		leftTableLeg0.transform.rotDegXYZ = glm::vec3(35.0f, 0.0f, 0.0f);

		leftTableLeg0.texture = "tabletop";
		leftTableLeg0.material = "wood";

		table.AddChild(leftTableLeg0);
		// --------------------------------------------
		MeshObject leftTableLeg1;
		leftTableLeg1.mesh = BOX;

		leftTableLeg1.transform.Reset();
		leftTableLeg1.transform.positionXYZ = glm::vec3(-4.5f, -1.5f, 0.0f);
		leftTableLeg1.transform.scaleXYZ = glm::vec3(0.25f, 3.5f, 0.8f);
		leftTableLeg1.transform.rotDegXYZ = glm::vec3(-35.0f, 0.0f, 0.0f);

		leftTableLeg1.texture = "tabletop";
		leftTableLeg1.material = "wood";

		table.AddChild(leftTableLeg1);
		// --------------------------------------------
		MeshObject leftTableLegsJoint;
		leftTableLegsJoint.mesh = BOX;

		leftTableLegsJoint.transform.Reset();
		leftTableLegsJoint.transform.positionXYZ = glm::vec3(-4.5f, -1.5f, 0.0f);
		leftTableLegsJoint.transform.scaleXYZ = glm::vec3(0.5f, 0.25f, 0.5f);

		leftTableLegsJoint.texture = "oldwood";
		leftTableLegsJoint.material = "wood";

		table.AddChild(leftTableLegsJoint);
		// -----------------------------------------------------------

		// Right Table Legs
		// -----------------------------------------------------------
		MeshObject rightTableLeg0;
		rightTableLeg0.mesh = BOX;

		rightTableLeg0.transform.Reset();
		rightTableLeg0.transform.positionXYZ = glm::vec3(4.5001f, -1.5f, 0.0f); // 4.5001f stops "z-fighting"
		rightTableLeg0.transform.scaleXYZ = glm::vec3(0.25f, 3.5f, 0.8f);
		rightTableLeg0.transform.rotDegXYZ = glm::vec3(35.0f, 0.0f, 0.0f);

		rightTableLeg0.texture = "tabletop";
		rightTableLeg0.material = "wood";

		table.AddChild(rightTableLeg0);
		// --------------------------------------------
		MeshObject rightTableLeg1;
		rightTableLeg1.mesh = BOX;

		rightTableLeg1.transform.Reset();
		rightTableLeg1.transform.positionXYZ = glm::vec3(4.5f, -1.5f, 0.0f);
		rightTableLeg1.transform.scaleXYZ = glm::vec3(0.25f, 3.5f, 0.8f);
		rightTableLeg1.transform.rotDegXYZ = glm::vec3(-35.0f, 0.0f, 0.0f);

		rightTableLeg1.texture = "tabletop";
		rightTableLeg1.material = "wood";

		table.AddChild(rightTableLeg1);
		// --------------------------------------------
		MeshObject rightTableLegsJoint;
		rightTableLegsJoint.mesh = BOX;

		rightTableLegsJoint.transform.Reset();
		rightTableLegsJoint.transform.positionXYZ = glm::vec3(4.5f, -1.5f, 0.0f);
		rightTableLegsJoint.transform.scaleXYZ = glm::vec3(0.5f, 0.25f, 0.5f);

		rightTableLegsJoint.texture = "oldwood";
		rightTableLegsJoint.material = "wood";

		table.AddChild(rightTableLegsJoint);
		// -----------------------------------------------------------

		table.SetTransform(compositeTransform);
		return table;
	}

	static CompositeMeshObject Room(Transform& compositeTransform)
	{
		CompositeMeshObject room;

		// Floor - (this will be the center of the composite mesh, a.k.a (0,0,0) )
		// -----------------------------------------------------------
		MeshObject floor;
		floor.mesh = PLANE;

		floor.transform.Reset();
		floor.transform.scaleXYZ = glm::vec3(6.0f, 1.0f, 6.0f);

		floor.color.Reset();

		floor.texture = "planks";
		floor.material = "wood";

		room.AddChild(floor);
		// -----------------------------------------------------------

		// Back Wall
		// -----------------------------------------------------------
		MeshObject backWall;
		backWall.mesh = PLANE;

		backWall.transform.Reset();
		backWall.transform.positionXYZ = glm::vec3(0.0f, 6.0f, -6.0f);
		backWall.transform.rotDegXYZ = glm::vec3(90.0f, 0.0f, 0.0f);
		backWall.transform.scaleXYZ = glm::vec3(6.0f, 1.0f, 6.0f);

		backWall.color.Reset();

		backWall.texture = "stone";
		backWall.material = "stone";

		room.AddChild(backWall);
		// --------------------------------------------
		/*
		MeshObject ledge;
		ledge.mesh = BOX;

		ledge.transform.Reset();
		ledge.transform.positionXYZ = glm::vec3(-3.0f, 5.0f, -5.75f);
		ledge.transform.scaleXYZ = glm::vec3(4.0f, 0.5f, 0.5f);

		ledge.texture = "stone";
		ledge.material = "stone";

		room.AddChild(ledge);
		*/
		// --------------------------------------------
		
		// -----------------------------------------------------------

		room.SetTransform(compositeTransform);
		return room;
	}

	static CompositeMeshObject Lantern(Transform& compositeTransform)
	{
		CompositeMeshObject lantern;

		// Base
		// -----------------------------------------------------------
		MeshObject base0;
		base0.mesh = CYLINDER;

		base0.transform.Reset();
		base0.transform.positionXYZ = glm::vec3(0.0f, 0.0f, 0.0f);
		base0.transform.scaleXYZ = glm::vec3(0.5f, 0.25f, 0.5f);

		base0.texture = "metal";
		base0.material = "metal";

		lantern.AddChild(base0);
		// --------------------------------------------
		MeshObject base1;
		base1.mesh = CYLINDER;

		base1.transform.Reset();
		base1.transform.positionXYZ = glm::vec3(0.0f, 0.2f, 0.0f);
		base1.transform.scaleXYZ = glm::vec3(0.4f, 0.2f, 0.4f);

		base1.texture = "metal";
		base1.material = "metal";

		lantern.AddChild(base1);
		// -----------------------------------------------------------

		// Glass
		// -----------------------------------------------------------
		MeshObject glass;
		glass.mesh = SPHERE;

		glass.transform.Reset();
		glass.transform.positionXYZ = glm::vec3(0.0f, 0.75f, 0.0f);
		glass.transform.scaleXYZ = glm::vec3(0.2f, 0.5f, 0.2f);

		glass.texture = "glass";
		glass.material = "glass";

		lantern.AddChild(glass);
		// -----------------------------------------------------------

		// Top
		// -----------------------------------------------------------
		MeshObject top;
		top.mesh = TAPERED_CYLINDER;

		top.transform.Reset();
		top.transform.positionXYZ = glm::vec3(0.0f, 1.2f, 0.0f);
		top.transform.scaleXYZ = glm::vec3(0.6f, 0.4f, 0.6f);

		top.texture = "metal";
		top.material = "metal";

		lantern.AddChild(top);
		// -----------------------------------------------------------

		lantern.SetTransform(compositeTransform);
		return lantern;
	}

	static CompositeMeshObject Book(Transform& compositeTransform, std::string color)
	{
		CompositeMeshObject book;

		// Cover
		// -----------------------------------------------------------
		MeshObject cover;
		cover.mesh = BOX;

		cover.transform.Reset();
		cover.transform.scaleXYZ = glm::vec3(0.75f, 0.25f, 1.0f);

		cover.texture = "flat";
		cover.material = "flat" + color;

		book.AddChild(cover);
		// -----------------------------------------------------------

		// Pages
		// -----------------------------------------------------------
		MeshObject pages;
		pages.mesh = BOX;

		pages.transform.Reset();
		pages.transform.positionXYZ = glm::vec3(0.001f, 0.0f, 0.0f);
		pages.transform.scaleXYZ = glm::vec3(0.75f, 0.175f, 1.001f);

		pages.texture = "flat";
		pages.material = "flatWhite";

		book.AddChild(pages);
		// -----------------------------------------------------------

		book.SetTransform(compositeTransform);
		return book;
	}

	static CompositeMeshObject PenAndPaper(Transform& compositeTransform)
	{
		CompositeMeshObject penAndPaper;

		// Paper
		// -----------------------------------------------------------
		MeshObject paper;
		paper.mesh = PLANE;

		paper.transform.Reset();
		paper.transform.scaleXYZ = glm::vec3(0.3f, 0.3f, 0.35f);
		paper.transform.rotDegXYZ = glm::vec3(0.0f, 20.0f, 0.0f);

		paper.texture = "flat";
		paper.material = "flatWhite";

		penAndPaper.AddChild(paper);
		// -----------------------------------------------------------

		// Pen
		// -----------------------------------------------------------
		MeshObject handle;
		handle.mesh = SPHERE;

		handle.transform.Reset();
		handle.transform.positionXYZ = glm::vec3(0.25f, 0.01f, -0.25f);
		handle.transform.scaleXYZ = glm::vec3(0.02f, 0.02f, 0.25f);
		handle.transform.rotDegXYZ = glm::vec3(0.0f, -10.0f, 0.0f);

		handle.texture = "darkwood";
		handle.material = "wood";

		penAndPaper.AddChild(handle);
		// --------------------------------------------
		MeshObject tip;
		tip.mesh = SPHERE;

		tip.transform.Reset();
		tip.transform.positionXYZ = glm::vec3(0.295f, 0.01f, -0.5f);
		tip.transform.scaleXYZ = glm::vec3(0.0075f, 0.0075f, 0.04f);
		tip.transform.rotDegXYZ = glm::vec3(0.0f, -10.0f, 0.0f);

		tip.texture = "flat";
		tip.material = "flatWhite";

		penAndPaper.AddChild(tip);
		// -----------------------------------------------------------

		penAndPaper.SetTransform(compositeTransform);
		return penAndPaper;
	}
	/*
	static CompositeMeshObject Chair(Transform& compositeTransform)
	{
		CompositeMeshObject chair;



		chair.SetTransform(compositeTransform);
		return chair;
	}
	*/
};