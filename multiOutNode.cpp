#include <maya/MIOStream.h>
#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnPlugin.h>
#include <maya/MString.h>
#include <maya/MTypeId.h>
#include <maya/MPlug.h>
#include <maya/MVector.h>
#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>
#include <maya/MGlobal.h>


//////////////////////////////////////////////////////////////////////////////////////////////////
/// This is a custom dependency node with one input and 10 outputs.							   ///					
/// Intended to be used for switching b/w different LOD meshes of an asset.					   ///			
/// Enum attribute can be connected to the input. Based on the input, the corresponding output ///
/// is set to 1 (active).																	   ///	 
/// Output can be connected to the visibility of the different LOD assets.					   ///
//////////////////////////////////////////////////////////////////////////////////////////////////

class multiOut : public MPxNode
{
public:
	multiOut();
	virtual ~multiOut();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);

	static void* creator();
	static MStatus initialize();

public:
	static MObject input;                //The input value
	static MObject output1;				//The output values
	static MObject output2;
	static MObject output3;
	static MObject output4;
	static MObject output5;
	static MObject output6;
	static MObject output7;
	static MObject output8;
	static MObject output9;
	static MObject output10;
	static MTypeId id;
};


MTypeId multiOut::id(0x00001000);
MObject multiOut::input;
MObject multiOut::output1;
MObject multiOut::output2;
MObject multiOut::output3;
MObject multiOut::output4;
MObject multiOut::output5;
MObject multiOut::output6;
MObject multiOut::output7;
MObject multiOut::output8;
MObject multiOut::output9;
MObject multiOut::output10;

multiOut::multiOut(){};

multiOut::~multiOut(){};

MStatus multiOut::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus returnStatus;

	if (plug == output1 || plug == output2 || plug == output3 || plug == output4 || plug == output5 ||
		plug == output6 || plug == output7 || plug == output8 || plug == output9 || plug == output10)
	{
		MDataHandle inputData = data.inputValue(input, &returnStatus);

		if (returnStatus != MS::kSuccess)
			cerr << "Error getting data" << endl;
		else
		{
			//based on the input value, corresponding output is enabled

			int inputValue = inputData.asInt();

			int inActive = 0;
			int active = 1;

			MDataHandle  outputHandle1 = data.outputValue(multiOut::output1);
			MDataHandle  outputHandle2 = data.outputValue(multiOut::output2);
			MDataHandle  outputHandle3 = data.outputValue(multiOut::output3);
			MDataHandle  outputHandle4 = data.outputValue(multiOut::output4);
			MDataHandle  outputHandle5 = data.outputValue(multiOut::output5);
			MDataHandle  outputHandle6 = data.outputValue(multiOut::output6);
			MDataHandle  outputHandle7 = data.outputValue(multiOut::output7);
			MDataHandle  outputHandle8 = data.outputValue(multiOut::output8);
			MDataHandle  outputHandle9 = data.outputValue(multiOut::output9);
			MDataHandle  outputHandle10 = data.outputValue(multiOut::output10);

			outputHandle1.setInt(inActive);
			outputHandle2.setInt(inActive);
			outputHandle3.setInt(inActive);
			outputHandle4.setInt(inActive);
			outputHandle5.setInt(inActive);
			outputHandle6.setInt(inActive);
			outputHandle7.setInt(inActive);
			outputHandle8.setInt(inActive);
			outputHandle9.setInt(inActive);
			outputHandle10.setInt(inActive);

			if (inputValue == 0)
				outputHandle1.setInt(active);
			else if (inputValue == 1)
				outputHandle2.setInt(active);
			else if (inputValue == 2)
				outputHandle3.setInt(active);
			else if (inputValue == 3)
				outputHandle4.setInt(active);
			else if (inputValue == 4)
				outputHandle5.setInt(active);
			else if (inputValue == 5)
				outputHandle6.setInt(active);
			else if (inputValue == 6)
				outputHandle7.setInt(active);
			else if (inputValue == 7)
				outputHandle8.setInt(active);
			else if (inputValue == 8)
				outputHandle9.setInt(active);
			else if (inputValue == 9)
				outputHandle10.setInt(active);



			data.setClean(plug);
			

		}
		
	}
	else
	{
		return MS::kUnknownParameter;		
	}

	return MS::kSuccess;
			
}

void* multiOut::creator()
{
	return new multiOut();

}

MStatus multiOut::initialize()
{
	MFnNumericAttribute nAttr;
	MStatus stat;

	input = nAttr.create("input", "in", MFnNumericData::kInt, 0);
	nAttr.setStorable(true);

	output1 = nAttr.create("output0", "out0", MFnNumericData::kInt, 0);
	nAttr.setWritable(false);
	nAttr.setStorable(false);

	output2 = nAttr.create("output1", "out1", MFnNumericData::kInt, 0);
	nAttr.setWritable(false);
	nAttr.setStorable(false);

	output3 = nAttr.create("output2", "out2", MFnNumericData::kInt, 0);
	nAttr.setWritable(false);
	nAttr.setStorable(false);

	output4 = nAttr.create("output3", "out3", MFnNumericData::kInt, 0);
	nAttr.setWritable(false);
	nAttr.setStorable(false);

	output5 = nAttr.create("output4", "out4", MFnNumericData::kInt, 0);
	nAttr.setWritable(false);
	nAttr.setStorable(false);

	output6 = nAttr.create("output5", "out5", MFnNumericData::kInt, 0);
	nAttr.setWritable(false);
	nAttr.setStorable(false);
		
	output7 = nAttr.create("output6", "out6", MFnNumericData::kInt, 0);
	nAttr.setWritable(false);
	nAttr.setStorable(false);
	
	output8 = nAttr.create("output7", "out7", MFnNumericData::kInt, 0);
	nAttr.setWritable(false);
	nAttr.setStorable(false);
	
	output9 = nAttr.create("output8", "out8", MFnNumericData::kInt, 0);
	nAttr.setWritable(false);
	nAttr.setStorable(false);
	
	output10 = nAttr.create("output9", "out9", MFnNumericData::kInt, 0);
	nAttr.setWritable(false);
	nAttr.setStorable(false);

	stat = addAttribute(input);
	if (!stat) { stat.perror("addAttribute"); return stat; }
	stat = addAttribute(output1);
	if (!stat) { stat.perror("addAttribute"); return stat; }
	stat = addAttribute(output2);
	if (!stat) { stat.perror("addAttribute"); return stat; }
	stat = addAttribute(output3);
	if (!stat) { stat.perror("addAttribute"); return stat; }
	stat = addAttribute(output4);
	if (!stat) { stat.perror("addAttribute"); return stat; }
	stat = addAttribute(output5);
	if (!stat) { stat.perror("addAttribute"); return stat; }
	stat = addAttribute(output6);
	if (!stat) { stat.perror("addAttribute"); return stat; }
	stat = addAttribute(output7);
	if (!stat) { stat.perror("addAttribute"); return stat; }
	stat = addAttribute(output8);
	if (!stat) { stat.perror("addAttribute"); return stat; }
	stat = addAttribute(output9);
	if (!stat) { stat.perror("addAttribute"); return stat; }
	stat = addAttribute(output10);
	if (!stat) { stat.perror("addAttribute"); return stat; }

	stat = attributeAffects(input, output1);
	if (!stat) { stat.perror("attributeAffects"); return stat; }

	stat = attributeAffects(input, output2);
	if (!stat) { stat.perror("attributeAffects"); return stat; }

	stat = attributeAffects(input, output3);
	if (!stat) { stat.perror("attributeAffects"); return stat; }

	stat = attributeAffects(input, output4);
	if (!stat) { stat.perror("attributeAffects"); return stat; }

	stat = attributeAffects(input, output5);
	if (!stat) { stat.perror("attributeAffects"); return stat; }

	stat = attributeAffects(input, output6);
	if (!stat) { stat.perror("attributeAffects"); return stat; }

	stat = attributeAffects(input, output7);
	if (!stat) { stat.perror("attributeAffects"); return stat; }

	stat = attributeAffects(input, output8);
	if (!stat) { stat.perror("attributeAffects"); return stat; }

	stat = attributeAffects(input, output9);
	if (!stat) { stat.perror("attributeAffects"); return stat; }

	stat = attributeAffects(input, output10);
	if (!stat) { stat.perror("attributeAffects"); return stat; }

	return MS::kSuccess;

}

MStatus initializePlugin(MObject obj)
{
	MStatus status;
	MFnPlugin plugin(obj, "Vaishak Babu", "1.0", "Any");

	status = plugin.registerNode("multiOut", multiOut::id, multiOut::creator, multiOut::initialize);
	if (!status)
	{
		status.perror("registerNode");
		return status;

	}

	return status;

}

MStatus uninitializePlugin(MObject obj)
{
	MStatus status;
	MFnPlugin plugin(obj);

	status = plugin.deregisterNode(multiOut::id);
	if (!status)
	{
		status.perror("deregisterNode");
		return status;

	}

	return status;

}

