xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 269;
 0.00000;1.67937;0.00000;,
 0.49689;1.67937;-0.49689;,
 0.00000;1.67937;-0.70270;,
 0.61981;1.73128;-0.61981;,
 0.00000;1.73128;-0.87654;,
 0.80000;1.67937;0.00000;,
 0.87654;1.73128;0.00000;,
 0.56569;1.67937;0.56569;,
 0.61981;1.73128;0.61981;,
 -0.00000;1.67937;0.80000;,
 -0.00000;1.73128;0.87654;,
 -0.56569;1.67937;0.56569;,
 -0.61981;1.73128;0.61980;,
 -0.80000;1.67937;-0.00000;,
 -0.87654;1.73128;-0.00000;,
 -0.56569;1.67937;-0.56569;,
 -0.61981;1.73128;-0.61980;,
 0.66569;1.68792;-0.66569;,
 0.00000;1.68792;-0.94142;,
 0.94142;1.68792;0.00000;,
 0.66569;1.68792;0.66569;,
 -0.00000;1.68792;0.94142;,
 -0.66569;1.68792;0.66569;,
 -0.94142;1.68792;-0.00000;,
 -0.66569;1.68792;-0.66569;,
 0.69634;1.62304;-0.69634;,
 0.00000;1.62304;-0.98478;,
 0.98478;1.62304;0.00000;,
 0.69634;1.62304;0.69634;,
 -0.00000;1.62304;0.98478;,
 -0.69634;1.62304;0.69634;,
 -0.98478;1.62304;-0.00000;,
 -0.69634;1.62304;-0.69634;,
 0.70711;1.54650;-0.70711;,
 0.00000;1.54650;-1.00000;,
 1.00000;1.54650;0.00000;,
 0.70711;1.54650;0.70711;,
 -0.00000;1.54650;1.00000;,
 -0.70711;1.54650;0.70711;,
 -1.00000;1.54650;-0.00000;,
 -0.70711;1.54650;-0.70711;,
 0.00000;-1.53869;-1.11042;,
 0.78519;-1.53869;-0.78519;,
 0.77323;-1.90131;-0.77323;,
 0.00000;-1.90131;-1.09351;,
 1.11042;-1.53869;0.00000;,
 1.09351;-1.90131;0.00000;,
 0.78519;-1.53869;0.78519;,
 0.77323;-1.90131;0.77323;,
 -0.00000;-1.53869;1.11042;,
 -0.00000;-1.90131;1.09351;,
 -0.78519;-1.53869;0.78518;,
 -0.77323;-1.90131;0.77323;,
 -1.11042;-1.53869;-0.00000;,
 -1.09351;-1.90131;-0.00000;,
 -0.78519;-1.53869;-0.78519;,
 -0.77323;-1.90131;-0.77323;,
 0.73919;-1.97335;-0.73919;,
 0.00000;-1.97335;-1.04537;,
 1.04537;-1.97335;0.00000;,
 0.73919;-1.97335;0.73919;,
 -0.00000;-1.97335;1.04537;,
 -0.73919;-1.97335;0.73919;,
 -1.04537;-1.97335;-0.00000;,
 -0.73919;-1.97335;-0.73919;,
 0.68824;-1.88136;-0.68824;,
 0.00000;-1.88136;-0.97332;,
 0.97332;-1.88136;0.00000;,
 0.68824;-1.88136;0.68824;,
 -0.00000;-1.88136;0.97332;,
 -0.68824;-1.88136;0.68824;,
 -0.97332;-1.88136;-0.00000;,
 -0.68824;-1.88136;-0.68824;,
 0.62815;-1.89826;-0.62815;,
 0.00000;-1.89826;-0.88834;,
 0.88834;-1.89826;0.00000;,
 0.62815;-1.89826;0.62815;,
 -0.00000;-1.89826;0.88834;,
 -0.62815;-1.89826;0.62815;,
 -0.88834;-1.89826;-0.00000;,
 -0.62815;-1.89826;-0.62815;,
 0.00000;-1.89826;-0.00000;,
 0.00000;1.67937;0.00000;,
 0.49689;1.67937;-0.49689;,
 0.00000;1.67937;-0.70270;,
 0.70270;1.67937;0.00000;,
 0.49689;1.67937;0.49689;,
 -0.00000;1.67937;0.70270;,
 -0.49689;1.67937;0.49689;,
 -0.70270;1.67937;-0.00000;,
 -0.49689;1.67937;-0.49689;,
 0.61981;1.73128;-0.61981;,
 0.00000;1.73128;-0.87654;,
 0.87654;1.73128;0.00000;,
 0.61981;1.73128;0.61981;,
 -0.00000;1.73128;0.87654;,
 -0.61981;1.73128;0.61980;,
 -0.87654;1.73128;-0.00000;,
 -0.61981;1.73128;-0.61980;,
 0.66569;1.68792;-0.66569;,
 0.00000;1.68792;-0.94142;,
 0.94142;1.68792;0.00000;,
 0.66569;1.68792;0.66569;,
 -0.00000;1.68792;0.94142;,
 -0.66569;1.68792;0.66569;,
 -0.94142;1.68792;-0.00000;,
 -0.66569;1.68792;-0.66569;,
 0.69634;1.62304;-0.69634;,
 0.00000;1.62304;-0.98478;,
 0.98478;1.62304;0.00000;,
 0.69634;1.62304;0.69634;,
 -0.00000;1.62304;0.98478;,
 -0.69634;1.62304;0.69634;,
 -0.98478;1.62304;-0.00000;,
 -0.69634;1.62304;-0.69634;,
 0.70711;1.54650;-0.70711;,
 0.00000;1.54650;-1.00000;,
 1.00000;1.54650;0.00000;,
 0.70711;1.54650;0.70711;,
 -0.00000;1.54650;1.00000;,
 -0.70711;1.54650;0.70711;,
 -1.00000;1.54650;-0.00000;,
 -0.70711;1.54650;-0.70711;,
 0.00000;-1.53869;-1.11042;,
 0.78519;-1.53869;-0.78519;,
 0.77323;-1.90131;-0.77323;,
 0.00000;-1.90131;-1.09351;,
 1.11042;-1.53869;0.00000;,
 1.09351;-1.90131;0.00000;,
 0.78519;-1.53869;0.78519;,
 0.77323;-1.90131;0.77323;,
 -0.00000;-1.53869;1.11042;,
 -0.00000;-1.90131;1.09351;,
 -0.78519;-1.53869;0.78518;,
 -0.77323;-1.90131;0.77323;,
 -1.11042;-1.53869;-0.00000;,
 -1.09351;-1.90131;-0.00000;,
 -0.78519;-1.53869;-0.78519;,
 -0.77323;-1.90131;-0.77323;,
 0.73919;-1.97335;-0.73919;,
 0.00000;-1.97335;-1.04537;,
 1.04537;-1.97335;0.00000;,
 0.73919;-1.97335;0.73919;,
 -0.00000;-1.97335;1.04537;,
 -0.73919;-1.97335;0.73919;,
 -1.04537;-1.97335;-0.00000;,
 -0.73919;-1.97335;-0.73919;,
 0.68824;-1.88136;-0.68824;,
 0.00000;-1.88136;-0.97332;,
 0.97332;-1.88136;0.00000;,
 0.68824;-1.88136;0.68824;,
 -0.00000;-1.88136;0.97332;,
 -0.68824;-1.88136;0.68824;,
 -0.97332;-1.88136;-0.00000;,
 -0.68824;-1.88136;-0.68824;,
 0.62815;-1.89826;-0.62815;,
 0.00000;-1.89826;-0.88834;,
 0.88834;-1.89826;0.00000;,
 0.62815;-1.89826;0.62815;,
 -0.00000;-1.89826;0.88834;,
 -0.62815;-1.89826;0.62815;,
 -0.88834;-1.89826;-0.00000;,
 -0.62815;-1.89826;-0.62815;,
 0.00000;-1.89826;-0.00000;,
 0.56569;1.62729;-0.56569;,
 0.80000;1.62729;0.00000;,
 0.00000;1.62729;0.00000;,
 0.56569;1.62729;0.56569;,
 -0.00000;1.62729;0.80000;,
 -0.56569;1.62729;0.56569;,
 -0.80000;1.62729;-0.00000;,
 -0.56569;1.62729;-0.56569;,
 0.00000;1.62729;-0.80000;,
 0.67270;0.74881;-0.67270;,
 0.00000;0.74881;-0.95135;,
 0.00000;0.82266;-0.95135;,
 0.67270;0.82266;-0.67270;,
 0.95135;0.74881;0.00000;,
 0.95135;0.82266;0.00000;,
 0.67270;0.74881;0.67270;,
 0.67270;0.82266;0.67270;,
 -0.00000;0.74881;0.95135;,
 -0.00000;0.82266;0.95135;,
 -0.67270;0.74881;0.67270;,
 -0.67270;0.82266;0.67270;,
 -0.95135;0.74881;-0.00000;,
 -0.95135;0.82266;-0.00000;,
 -0.67270;0.74881;-0.67270;,
 -0.67270;0.82266;-0.67270;,
 0.67270;0.74881;-0.67270;,
 0.00000;0.74881;-0.95135;,
 0.00000;0.82266;-0.95135;,
 0.67270;0.82266;-0.67270;,
 0.95135;0.74881;0.00000;,
 0.95135;0.82266;0.00000;,
 0.67270;0.74881;0.67270;,
 0.67270;0.82266;0.67270;,
 -0.00000;0.74881;0.95135;,
 -0.00000;0.82266;0.95135;,
 -0.67270;0.74881;0.67270;,
 -0.67270;0.82266;0.67270;,
 -0.95135;0.74881;-0.00000;,
 -0.95135;0.82266;-0.00000;,
 -0.67270;0.74881;-0.67270;,
 -0.67270;0.82266;-0.67270;,
 0.00000;0.90674;-1.00000;,
 0.70711;0.90674;-0.70711;,
 1.00000;0.90674;0.00000;,
 0.70711;0.90674;0.70711;,
 -0.00000;0.90674;1.00000;,
 -0.70711;0.90674;0.70711;,
 -1.00000;0.90674;-0.00000;,
 -0.70711;0.90674;-0.70711;,
 0.00000;0.90674;-1.00000;,
 0.70711;0.90674;-0.70711;,
 1.00000;0.90674;0.00000;,
 0.70711;0.90674;0.70711;,
 -0.00000;0.90674;1.00000;,
 -0.70711;0.90674;0.70711;,
 -1.00000;0.90674;-0.00000;,
 -0.70711;0.90674;-0.70711;,
 0.70711;0.65103;-0.70711;,
 0.00000;0.65103;-1.00000;,
 1.00000;0.65103;0.00000;,
 0.70711;0.65103;0.70711;,
 -0.00000;0.65103;1.00000;,
 -0.70711;0.65103;0.70711;,
 -1.00000;0.65103;-0.00000;,
 -0.70711;0.65103;-0.70711;,
 0.70711;0.65103;-0.70711;,
 0.00000;0.65103;-1.00000;,
 1.00000;0.65103;0.00000;,
 0.70711;0.65103;0.70711;,
 -0.00000;0.65103;1.00000;,
 -0.70711;0.65103;0.70711;,
 -1.00000;0.65103;-0.00000;,
 -0.70711;0.65103;-0.70711;,
 0.65942;-1.07499;-0.65942;,
 0.00000;-1.07499;-0.93256;,
 0.93256;-1.07499;0.00000;,
 0.65942;-1.07499;0.65942;,
 -0.00000;-1.07499;0.93256;,
 -0.65942;-1.07499;0.65942;,
 -0.93256;-1.07499;-0.00000;,
 -0.65942;-1.07499;-0.65942;,
 0.65942;-1.07499;-0.65942;,
 0.00000;-1.07499;-0.93256;,
 0.93256;-1.07499;0.00000;,
 0.65942;-1.07499;0.65942;,
 -0.00000;-1.07499;0.93256;,
 -0.65942;-1.07499;0.65942;,
 -0.93256;-1.07499;-0.00000;,
 -0.65942;-1.07499;-0.65942;,
 0.00000;-0.53161;-1.00000;,
 0.70711;-0.53161;-0.70711;,
 1.00000;-0.53161;0.00000;,
 0.70711;-0.53161;0.70711;,
 -0.00000;-0.53161;1.00000;,
 -0.70711;-0.53161;0.70711;,
 -1.00000;-0.53161;-0.00000;,
 -0.70711;-0.53161;-0.70711;,
 0.00000;-0.53161;-1.00000;,
 0.70711;-0.53161;-0.70711;,
 1.00000;-0.53161;0.00000;,
 0.70711;-0.53161;0.70711;,
 -0.00000;-0.53161;1.00000;,
 -0.70711;-0.53161;0.70711;,
 -1.00000;-0.53161;-0.00000;,
 -0.70711;-0.53161;-0.70711;;
 
 281;
 3;0,1,2;,
 4;2,1,3,4;,
 4;1,5,6,3;,
 4;5,7,8,6;,
 4;7,9,10,8;,
 4;9,11,12,10;,
 4;11,13,14,12;,
 4;13,15,16,14;,
 4;15,2,4,16;,
 4;4,3,17,18;,
 4;3,6,19,17;,
 4;6,8,20,19;,
 4;8,10,21,20;,
 4;10,12,22,21;,
 4;12,14,23,22;,
 4;14,16,24,23;,
 4;16,4,18,24;,
 4;18,17,25,26;,
 4;17,19,27,25;,
 4;19,20,28,27;,
 4;20,21,29,28;,
 4;21,22,30,29;,
 4;22,23,31,30;,
 4;23,24,32,31;,
 4;24,18,26,32;,
 4;26,25,33,34;,
 4;25,27,35,33;,
 4;27,28,36,35;,
 4;28,29,37,36;,
 4;29,30,38,37;,
 4;30,31,39,38;,
 4;31,32,40,39;,
 4;32,26,34,40;,
 4;41,42,43,44;,
 4;42,45,46,43;,
 4;45,47,48,46;,
 4;47,49,50,48;,
 4;49,51,52,50;,
 4;51,53,54,52;,
 4;53,55,56,54;,
 4;55,41,44,56;,
 4;44,43,57,58;,
 4;43,46,59,57;,
 4;46,48,60,59;,
 4;48,50,61,60;,
 4;50,52,62,61;,
 4;52,54,63,62;,
 4;54,56,64,63;,
 4;56,44,58,64;,
 4;58,57,65,66;,
 4;57,59,67,65;,
 4;59,60,68,67;,
 4;60,61,69,68;,
 4;61,62,70,69;,
 4;62,63,71,70;,
 4;63,64,72,71;,
 4;64,58,66,72;,
 4;66,65,73,74;,
 4;65,67,75,73;,
 4;67,68,76,75;,
 4;68,69,77,76;,
 4;69,70,78,77;,
 4;70,71,79,78;,
 4;71,72,80,79;,
 4;72,66,74,80;,
 3;74,73,81;,
 3;73,75,81;,
 3;75,76,81;,
 3;76,77,81;,
 3;77,78,81;,
 3;78,79,81;,
 3;79,80,81;,
 3;80,74,81;,
 3;82,83,84;,
 3;82,85,83;,
 3;82,86,85;,
 3;82,87,86;,
 3;82,88,87;,
 3;82,89,88;,
 3;82,90,89;,
 3;82,84,90;,
 4;84,83,91,92;,
 4;83,85,93,91;,
 4;85,86,94,93;,
 4;86,87,95,94;,
 4;87,88,96,95;,
 4;88,89,97,96;,
 4;89,90,98,97;,
 4;90,84,92,98;,
 4;92,91,99,100;,
 4;91,93,101,99;,
 4;93,94,102,101;,
 4;94,95,103,102;,
 4;95,96,104,103;,
 4;96,97,105,104;,
 4;97,98,106,105;,
 4;98,92,100,106;,
 4;100,99,107,108;,
 4;99,101,109,107;,
 4;101,102,110,109;,
 4;102,103,111,110;,
 4;103,104,112,111;,
 4;104,105,113,112;,
 4;105,106,114,113;,
 4;106,100,108,114;,
 4;108,107,115,116;,
 4;107,109,117,115;,
 4;109,110,118,117;,
 4;110,111,119,118;,
 4;111,112,120,119;,
 4;112,113,121,120;,
 4;113,114,122,121;,
 4;114,108,116,122;,
 4;123,124,125,126;,
 4;124,127,128,125;,
 4;127,129,130,128;,
 4;129,131,132,130;,
 4;131,133,134,132;,
 4;133,135,136,134;,
 4;135,137,138,136;,
 4;137,123,126,138;,
 4;126,125,139,140;,
 4;125,128,141,139;,
 4;128,130,142,141;,
 4;130,132,143,142;,
 4;132,134,144,143;,
 4;134,136,145,144;,
 4;136,138,146,145;,
 4;138,126,140,146;,
 4;140,139,147,148;,
 4;139,141,149,147;,
 4;141,142,150,149;,
 4;142,143,151,150;,
 4;143,144,152,151;,
 4;144,145,153,152;,
 4;145,146,154,153;,
 4;146,140,148,154;,
 4;148,147,155,156;,
 4;147,149,157,155;,
 4;149,150,158,157;,
 4;150,151,159,158;,
 4;151,152,160,159;,
 4;152,153,161,160;,
 4;153,154,162,161;,
 4;154,148,156,162;,
 3;156,155,163;,
 3;155,157,163;,
 3;157,158,163;,
 3;158,159,163;,
 3;159,160,163;,
 3;160,161,163;,
 3;161,162,163;,
 3;162,156,163;,
 4;164,165,5,1;,
 4;166,164,1,0;,
 3;166,165,164;,
 4;165,167,7,5;,
 3;166,167,165;,
 4;167,168,9,7;,
 3;166,168,167;,
 4;168,169,11,9;,
 3;166,169,168;,
 4;169,170,13,11;,
 3;166,170,169;,
 4;170,171,15,13;,
 3;166,171,170;,
 4;172,166,0,2;,
 4;171,172,2,15;,
 3;166,172,171;,
 4;173,174,175,176;,
 4;177,173,176,178;,
 4;179,177,178,180;,
 4;181,179,180,182;,
 4;183,181,182,184;,
 4;185,183,184,186;,
 4;187,185,186,188;,
 4;174,187,188,175;,
 4;189,190,191,192;,
 4;193,189,192,194;,
 4;195,193,194,196;,
 4;197,195,196,198;,
 4;199,197,198,200;,
 4;201,199,200,202;,
 4;203,201,202,204;,
 4;190,203,204,191;,
 4;205,34,33,206;,
 4;205,206,176,175;,
 4;206,33,35,207;,
 4;206,207,178,176;,
 4;207,35,36,208;,
 4;207,208,180,178;,
 4;208,36,37,209;,
 4;208,209,182,180;,
 4;209,37,38,210;,
 4;209,210,184,182;,
 4;210,38,39,211;,
 4;210,211,186,184;,
 4;211,39,40,212;,
 4;211,212,188,186;,
 4;212,40,34,205;,
 4;212,205,175,188;,
 4;213,116,115,214;,
 4;213,214,192,191;,
 4;214,115,117,215;,
 4;214,215,194,192;,
 4;215,117,118,216;,
 4;215,216,196,194;,
 4;216,118,119,217;,
 4;216,217,198,196;,
 4;217,119,120,218;,
 4;217,218,200,198;,
 4;218,120,121,219;,
 4;218,219,202,200;,
 4;219,121,122,220;,
 4;219,220,204,202;,
 4;220,122,116,213;,
 4;220,213,191,204;,
 4;221,222,174,173;,
 4;223,221,173,177;,
 4;224,223,177,179;,
 4;225,224,179,181;,
 4;226,225,181,183;,
 4;227,226,183,185;,
 4;228,227,185,187;,
 4;222,228,187,174;,
 4;229,230,190,189;,
 4;231,229,189,193;,
 4;232,231,193,195;,
 4;233,232,195,197;,
 4;234,233,197,199;,
 4;235,234,199,201;,
 4;236,235,201,203;,
 4;230,236,203,190;,
 4;237,42,41,238;,
 4;239,45,42,237;,
 4;240,47,45,239;,
 4;241,49,47,240;,
 4;242,51,49,241;,
 4;243,53,51,242;,
 4;244,55,53,243;,
 4;238,41,55,244;,
 4;245,124,123,246;,
 4;247,127,124,245;,
 4;248,129,127,247;,
 4;249,131,129,248;,
 4;250,133,131,249;,
 4;251,135,133,250;,
 4;252,137,135,251;,
 4;246,123,137,252;,
 4;253,222,221,254;,
 4;253,254,237,238;,
 4;254,221,223,255;,
 4;254,255,239,237;,
 4;255,223,224,256;,
 4;255,256,240,239;,
 4;256,224,225,257;,
 4;256,257,241,240;,
 4;257,225,226,258;,
 4;257,258,242,241;,
 4;258,226,227,259;,
 4;258,259,243,242;,
 4;259,227,228,260;,
 4;259,260,244,243;,
 4;260,228,222,253;,
 4;260,253,238,244;,
 4;261,230,229,262;,
 4;261,262,245,246;,
 4;262,229,231,263;,
 4;262,263,247,245;,
 4;263,231,232,264;,
 4;263,264,248,247;,
 4;264,232,233,265;,
 4;264,265,249,248;,
 4;265,233,234,266;,
 4;265,266,250,249;,
 4;266,234,235,267;,
 4;266,267,251,250;,
 4;267,235,236,268;,
 4;267,268,252,251;,
 4;268,236,230,261;,
 4;268,261,246,252;;
 
 MeshMaterialList {
  5;
  281;
  0,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  4,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4;;
  Material {
   0.700000;0.288235;0.038431;1.000000;;
   10.000000;
   0.000000;0.000000;0.000000;;
   0.100000;0.041176;0.005490;;
  }
  Material {
   0.800000;0.398431;0.225882;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.820000;0.408392;0.231529;;
  }
  Material {
   0.800000;0.263529;0.241569;1.000000;;
   5.000000;
   0.340000;0.340000;0.340000;;
   1.000000;0.329412;0.301961;;
  }
  Material {
   0.235294;0.235294;0.235294;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  164;
  0.000000;1.000000;0.000000;,
  0.011011;0.970485;0.240909;,
  -0.178135;0.970485;0.162563;,
  -0.488244;0.872533;-0.017427;,
  -0.620063;0.480671;-0.620063;,
  0.000000;0.480671;-0.876901;,
  0.620063;0.480671;-0.620062;,
  0.876901;0.480671;0.000000;,
  0.357564;0.872533;0.332918;,
  0.009260;0.994110;-0.107976;,
  0.069803;0.994110;-0.082898;,
  -0.396903;0.827609;-0.396903;,
  0.000000;0.827609;-0.561306;,
  0.396903;0.827609;-0.396903;,
  0.561306;0.827609;-0.000000;,
  -0.000000;0.709231;-0.704976;,
  0.498494;0.709231;-0.498494;,
  0.704976;0.709231;0.000000;,
  0.498494;0.709231;0.498494;,
  -0.000000;0.709231;0.704977;,
  -0.498494;0.709231;0.498494;,
  -0.704976;0.709231;-0.000000;,
  -0.498494;0.709231;-0.498494;,
  -0.000000;0.384551;-0.923104;,
  0.652733;0.384551;-0.652733;,
  0.923104;0.384551;0.000000;,
  0.652733;0.384551;0.652733;,
  -0.000000;0.384551;0.923104;,
  -0.652733;0.384551;0.652733;,
  -0.923104;0.384551;-0.000000;,
  -0.652733;0.384551;-0.652733;,
  -0.000000;0.098154;-0.995171;,
  0.703692;0.098154;-0.703692;,
  0.995171;0.098154;0.000000;,
  0.703692;0.098154;0.703692;,
  -0.000000;0.098154;0.995171;,
  -0.703692;0.098154;0.703692;,
  -0.995171;0.098154;-0.000000;,
  -0.703692;0.098154;-0.703692;,
  -0.000000;0.160124;-0.987097;,
  0.697983;0.160124;-0.697983;,
  0.987097;0.160124;0.000000;,
  0.697983;0.160124;0.697983;,
  -0.000000;0.160124;0.987097;,
  -0.697983;0.160124;0.697983;,
  -0.987097;0.160124;-0.000000;,
  -0.697983;0.160124;-0.697983;,
  0.000000;-0.315529;-0.948916;,
  0.670985;-0.315528;-0.670985;,
  0.948916;-0.315528;0.000000;,
  0.670985;-0.315528;0.670985;,
  -0.000000;-0.315528;0.948916;,
  -0.670985;-0.315529;0.670985;,
  -0.948916;-0.315529;-0.000000;,
  -0.670985;-0.315529;-0.670985;,
  0.000000;-0.555574;-0.831467;,
  0.587936;-0.555574;-0.587936;,
  0.831467;-0.555574;0.000000;,
  0.587936;-0.555574;0.587936;,
  0.000000;-0.555574;0.831467;,
  -0.587936;-0.555574;0.587936;,
  -0.831467;-0.555575;0.000000;,
  -0.587936;-0.555574;-0.587936;,
  0.000000;-0.616583;0.787290;,
  -0.556698;-0.616582;0.556698;,
  -0.787290;-0.616582;0.000000;,
  -0.556698;-0.616582;-0.556699;,
  0.000000;-0.616582;-0.787290;,
  0.556699;-0.616582;-0.556698;,
  0.787291;-0.616582;-0.000000;,
  0.556698;-0.616582;0.556698;,
  -0.000000;-0.995201;-0.097856;,
  0.069195;-0.995201;-0.069195;,
  0.097856;-0.995201;0.000000;,
  0.069195;-0.995201;0.069195;,
  0.000000;-0.995201;0.097856;,
  -0.069195;-0.995201;0.069195;,
  -0.097856;-0.995201;-0.000000;,
  -0.069195;-0.995201;-0.069195;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.989566;0.144080;,
  -0.101880;0.989566;0.101880;,
  -0.144080;0.989566;-0.000000;,
  -0.101880;0.989566;-0.101880;,
  0.000000;0.989566;-0.144080;,
  0.101880;0.989566;-0.101880;,
  0.144080;0.989566;0.000000;,
  0.101880;0.989566;0.101880;,
  0.000000;0.989505;-0.144497;,
  0.102175;0.989505;-0.102175;,
  0.144497;0.989505;-0.000000;,
  0.102175;0.989505;0.102175;,
  0.000000;0.989505;0.144497;,
  -0.102175;0.989505;0.102175;,
  -0.144497;0.989505;-0.000000;,
  -0.102175;0.989505;-0.102175;,
  0.707107;0.000000;0.707107;,
  -1.000000;0.000000;0.000000;,
  -0.761459;-0.500376;0.412072;,
  -0.958506;-0.284580;0.016714;,
  -0.707107;0.000000;-0.707107;,
  0.000000;0.000000;-1.000000;,
  0.707107;0.000000;-0.707107;,
  1.000000;0.000000;0.000000;,
  0.665948;-0.284580;0.689585;,
  -0.000000;-0.261712;-0.965146;,
  0.682461;-0.261712;-0.682461;,
  0.965146;-0.261712;0.000000;,
  0.682461;-0.261712;0.682461;,
  -0.000000;-0.261712;0.965146;,
  -0.682461;-0.261712;0.682461;,
  -0.965146;-0.261712;-0.000000;,
  -0.682461;-0.261712;-0.682461;,
  -0.000000;0.230495;-0.973074;,
  0.688067;0.230495;-0.688067;,
  0.973074;0.230495;0.000000;,
  0.688067;0.230495;0.688067;,
  -0.000000;0.230495;0.973074;,
  -0.688067;0.230495;0.688067;,
  -0.973073;0.230495;-0.000000;,
  -0.688067;0.230495;-0.688067;,
  -0.000000;-0.261712;-0.965146;,
  0.682461;-0.261712;-0.682461;,
  0.965146;-0.261712;0.000000;,
  -0.000000;-0.261712;0.965146;,
  -0.682461;-0.261712;0.682461;,
  -0.000000;0.230495;-0.973073;,
  0.688067;0.230495;-0.688067;,
  0.973073;0.230495;0.000000;,
  0.688067;0.230495;0.688067;,
  -0.000000;0.230495;0.973074;,
  -0.973074;0.230495;-0.000000;,
  -0.000000;0.122129;-0.992514;,
  0.701814;0.122129;-0.701814;,
  0.992514;0.122129;0.000000;,
  0.701813;0.122129;0.701814;,
  -0.000000;0.122129;0.992514;,
  -0.701814;0.122129;0.701813;,
  -0.992514;0.122129;-0.000000;,
  -0.701814;0.122129;-0.701813;,
  -0.000000;-0.061739;-0.998092;,
  0.705758;-0.061739;-0.705758;,
  0.998092;-0.061739;0.000000;,
  0.705758;-0.061739;0.705758;,
  -0.000000;-0.061739;0.998092;,
  -0.705758;-0.061739;0.705758;,
  -0.998092;-0.061739;-0.000000;,
  -0.705758;-0.061739;-0.705758;,
  0.555570;0.831470;0.000000;,
  0.392847;0.831470;0.392847;,
  -0.000000;0.831470;0.555570;,
  -0.392847;0.831470;0.392847;,
  -0.555570;0.831470;-0.000000;,
  -0.392847;0.831470;-0.392847;,
  -0.000000;-0.980786;-0.195088;,
  0.137948;-0.980786;-0.137948;,
  0.195088;-0.980786;0.000000;,
  0.137948;-0.980786;0.137948;,
  0.000000;-0.980786;0.195088;,
  -0.137948;-0.980786;0.137948;,
  -0.195088;-0.980786;-0.000000;,
  -0.137948;-0.980786;-0.137948;,
  0.000000;1.000000;0.000000;,
  0.247054;-0.500376;0.829812;;
  281;
  3;0,2,1;,
  4;1,2,10,9;,
  4;2,3,3,10;,
  4;3,4,11,3;,
  4;4,5,12,11;,
  4;5,6,13,12;,
  4;6,7,14,13;,
  4;7,8,8,14;,
  4;8,1,9,8;,
  4;9,10,16,15;,
  4;10,148,17,16;,
  4;148,149,18,17;,
  4;149,150,19,18;,
  4;150,151,20,19;,
  4;151,152,21,20;,
  4;152,153,22,21;,
  4;153,9,15,22;,
  4;15,16,24,23;,
  4;16,17,25,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,15,23,30;,
  4;23,24,32,31;,
  4;24,25,33,32;,
  4;25,26,34,33;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;30,23,31,38;,
  4;39,40,48,47;,
  4;40,41,49,48;,
  4;41,42,50,49;,
  4;42,43,51,50;,
  4;43,44,52,51;,
  4;44,45,53,52;,
  4;45,46,54,53;,
  4;46,39,47,54;,
  4;47,48,56,55;,
  4;48,49,57,56;,
  4;49,50,58,57;,
  4;50,51,59,58;,
  4;51,52,60,59;,
  4;52,53,61,60;,
  4;53,54,62,61;,
  4;54,47,55,62;,
  4;63,64,64,63;,
  4;64,65,65,64;,
  4;65,66,66,65;,
  4;66,67,67,66;,
  4;67,68,68,67;,
  4;68,69,69,68;,
  4;69,70,70,69;,
  4;70,63,63,70;,
  4;154,155,72,71;,
  4;155,156,73,72;,
  4;156,157,74,73;,
  4;157,158,75,74;,
  4;158,159,76,75;,
  4;159,160,77,76;,
  4;160,161,78,77;,
  4;161,154,71,78;,
  3;71,72,79;,
  3;72,73,79;,
  3;73,74,79;,
  3;74,75,79;,
  3;75,76,79;,
  3;76,77,79;,
  3;77,78,79;,
  3;78,71,79;,
  3;0,81,80;,
  3;0,82,81;,
  3;0,83,82;,
  3;0,84,83;,
  3;0,85,84;,
  3;0,86,85;,
  3;0,87,86;,
  3;0,80,87;,
  4;80,81,89,88;,
  4;81,82,90,89;,
  4;82,83,91,90;,
  4;83,84,92,91;,
  4;84,85,93,92;,
  4;85,86,94,93;,
  4;86,87,95,94;,
  4;87,80,88,95;,
  4;88,89,16,15;,
  4;89,90,17,16;,
  4;90,91,18,17;,
  4;91,92,19,18;,
  4;92,93,20,19;,
  4;93,94,21,20;,
  4;94,95,22,21;,
  4;95,88,15,22;,
  4;15,16,24,23;,
  4;16,17,25,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,15,23,30;,
  4;23,24,32,31;,
  4;24,25,33,32;,
  4;25,26,34,33;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;30,23,31,38;,
  4;39,40,48,47;,
  4;40,41,49,48;,
  4;41,42,50,49;,
  4;42,43,51,50;,
  4;43,44,52,51;,
  4;44,45,53,52;,
  4;45,46,54,53;,
  4;46,39,47,54;,
  4;47,48,56,55;,
  4;48,49,57,56;,
  4;49,50,58,57;,
  4;50,51,59,58;,
  4;51,52,60,59;,
  4;52,53,61,60;,
  4;53,54,62,61;,
  4;54,47,55,62;,
  4;63,64,64,63;,
  4;64,65,65,64;,
  4;65,66,66,65;,
  4;66,67,67,66;,
  4;67,68,68,67;,
  4;68,69,69,68;,
  4;69,70,70,69;,
  4;70,63,63,70;,
  4;154,155,72,71;,
  4;155,156,73,72;,
  4;156,157,74,73;,
  4;157,158,75,74;,
  4;158,159,76,75;,
  4;159,160,77,76;,
  4;160,161,78,77;,
  4;161,154,71,78;,
  3;71,72,79;,
  3;72,73,79;,
  3;73,74,79;,
  3;74,75,79;,
  3;75,76,79;,
  3;76,77,79;,
  3;77,78,79;,
  3;78,71,79;,
  4;98,99,99,98;,
  4;96,96,96,96;,
  3;0,0,162;,
  4;99,100,4,99;,
  3;0,0,0;,
  4;100,101,5,4;,
  3;0,0,0;,
  4;101,102,6,5;,
  3;0,0,0;,
  4;102,103,7,6;,
  3;0,0,0;,
  4;103,104,104,7;,
  3;0,0,0;,
  4;97,97,97,97;,
  4;104,163,163,104;,
  3;0,0,0;,
  4;114,113,105,106;,
  4;115,114,106,107;,
  4;116,115,107,108;,
  4;117,116,108,109;,
  4;118,117,109,110;,
  4;119,118,110,111;,
  4;120,119,111,112;,
  4;113,120,112,105;,
  4;114,113,105,106;,
  4;115,114,106,107;,
  4;116,115,107,108;,
  4;117,116,108,109;,
  4;118,117,109,110;,
  4;119,118,110,111;,
  4;120,119,111,112;,
  4;113,120,112,105;,
  4;121,31,32,122;,
  4;121,122,106,105;,
  4;122,32,33,123;,
  4;122,123,107,106;,
  4;123,33,34,108;,
  4;123,108,108,107;,
  4;108,34,35,124;,
  4;108,124,109,108;,
  4;124,35,36,125;,
  4;124,125,110,109;,
  4;125,36,37,111;,
  4;125,111,111,110;,
  4;111,37,38,112;,
  4;111,112,112,111;,
  4;112,38,31,121;,
  4;112,121,105,112;,
  4;121,31,32,122;,
  4;121,122,106,105;,
  4;122,32,33,123;,
  4;122,123,107,106;,
  4;123,33,34,108;,
  4;123,108,108,107;,
  4;108,34,35,124;,
  4;108,124,109,108;,
  4;124,35,36,125;,
  4;124,125,110,109;,
  4;125,36,37,111;,
  4;125,111,111,110;,
  4;111,37,38,112;,
  4;111,112,112,111;,
  4;112,38,31,121;,
  4;112,121,105,112;,
  4;127,126,113,114;,
  4;128,127,114,115;,
  4;129,128,115,116;,
  4;130,129,116,117;,
  4;118,130,117,118;,
  4;131,118,118,119;,
  4;120,131,119,120;,
  4;126,120,120,113;,
  4;127,126,113,114;,
  4;128,127,114,115;,
  4;129,128,115,116;,
  4;130,129,116,117;,
  4;118,130,117,118;,
  4;131,118,118,119;,
  4;120,131,119,120;,
  4;126,120,120,113;,
  4;133,40,39,132;,
  4;134,41,40,133;,
  4;135,42,41,134;,
  4;136,43,42,135;,
  4;137,44,43,136;,
  4;138,45,44,137;,
  4;139,46,45,138;,
  4;132,39,46,139;,
  4;133,40,39,132;,
  4;134,41,40,133;,
  4;135,42,41,134;,
  4;136,43,42,135;,
  4;137,44,43,136;,
  4;138,45,44,137;,
  4;139,46,45,138;,
  4;132,39,46,139;,
  4;140,126,127,141;,
  4;140,141,133,132;,
  4;141,127,128,142;,
  4;141,142,134,133;,
  4;142,128,129,143;,
  4;142,143,135,134;,
  4;143,129,130,144;,
  4;143,144,136,135;,
  4;144,130,118,145;,
  4;144,145,137,136;,
  4;145,118,131,146;,
  4;145,146,138,137;,
  4;146,131,120,147;,
  4;146,147,139,138;,
  4;147,120,126,140;,
  4;147,140,132,139;,
  4;140,126,127,141;,
  4;140,141,133,132;,
  4;141,127,128,142;,
  4;141,142,134,133;,
  4;142,128,129,143;,
  4;142,143,135,134;,
  4;143,129,130,144;,
  4;143,144,136,135;,
  4;144,130,118,145;,
  4;144,145,137,136;,
  4;145,118,131,146;,
  4;145,146,138,137;,
  4;146,131,120,147;,
  4;146,147,139,138;,
  4;147,120,126,140;,
  4;147,140,132,139;;
 }
 MeshTextureCoords {
  269;
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;;
 }
}