Network vgg16 {
	Layer CONV1 { 
		Type: CONV
		Dimensions { K 64,C 3,R 3,S 3,Y 224,X 224 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(Sz(K),Sz(K)) K;
			TemporalMap(112,112) Y';
			TemporalMap(112,112) X';		
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(Sz(K), P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV2 { 
		Type: CONV
		Dimensions { K 64,C 64,R 3,S 3,Y 224,X 224 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(112,112) Y';
			TemporalMap(112,112) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV3 { 
		Type: CONV
		Dimensions { K 128,C 64,R 3,S 3,Y 112,X 112 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(56,56) Y';
			TemporalMap(56,56) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV4 { 
		Type: CONV
		Dimensions { K 128,C 128,R 3,S 3,Y 112,X 112 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(56,56) Y';
			TemporalMap(56,56) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV5 { 
		Type: CONV
		Dimensions { K 256,C 128,R 3,S 3,Y 56,X 56 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(28,28) Y';
			TemporalMap(28,28) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV6 { 
		Type: CONV
		Dimensions { K 256,C 256,R 3,S 3,Y 56,X 56 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(28,28) Y';
			TemporalMap(28,28) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV7 { 
		Type: CONV
		Dimensions { K 256,C 256,R 3,S 3,Y 56,X 56 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(28,28) Y';
			TemporalMap(28,28) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);;
			SpatialMap(1,1) K;
		}
	}

	Layer CONV8 { 
		Type: CONV
		Dimensions { K 512,C 256,R 3,S 3,Y 28,X 28 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(14,14) Y';
			TemporalMap(14,14) X';;
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV9 { 
		Type: CONV
		Dimensions { K 512,C 512,R 3,S 3,Y 28,X 28 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(14,14) Y';
			TemporalMap(14,14) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV10 { 
		Type: CONV
		Dimensions { K 512,C 512,R 3,S 3,Y 28,X 28 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(14,14) Y';
			TemporalMap(14,14) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);;
			SpatialMap(1,1) K;
		}
	}

	Layer CONV11 { 
		Type: CONV
		Dimensions { K 512,C 512,R 3,S 3,Y 14,X 14 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(7,7) Y';
			TemporalMap(7,7) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV12 { 
		Type: CONV
		Dimensions { K 512,C 512,R 3,S 3,Y 14,X 14 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(7,7) Y';
			TemporalMap(7,7) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV13 { 
		Type: CONV
		Dimensions { K 512,C 512,R 3,S 3,Y 14,X 14 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(7,7) Y';
			TemporalMap(7,7) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer FC1 { 
		Type: GEMM
		Dimensions { M 4096, N 1, K 25088 }
		Dataflow {
			SpatialMap(1,1) N;
			TemporalMap(1024,1024) K;
			TemporalMap(4096,4096) M;
			Cluster(1024, P);
			SpatialMap(1,1) K;
		}
	}

	Layer FC2 { 
		Type: GEMM
		Dimensions { M 4096, N 1, K 4096 }
		Dataflow {
			SpatialMap(1,1) N;
			TemporalMap(1024,1024) K;
			TemporalMap(4096,4096) M;
			Cluster(1024, P);
			SpatialMap(1,1) K;
		}
	}

	Layer FC3 { 
		Type: GEMM
		Dimensions { M 4096, N 1, K 4096 }
		Dataflow {
			SpatialMap(1,1) N;
			TemporalMap(1024,1024) K;
			TemporalMap(4096,4096) M;
			Cluster(1024, P);
			SpatialMap(1,1) K;
		}
	}
}
