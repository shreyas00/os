Network UNet {
	Layer CONV1_1 {
		Type: CONV
		Dimensions { K: 64, C:1, R: 3, S: 3, Y: 572, X: 572 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(Sz(K),Sz(K)) K;
			TemporalMap(286,286) Y';
			TemporalMap(286,286) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(Sz(K), P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV1_2 {
		Type: CONV
		Dimensions { K: 64, C: 64, R: 3, S: 3, Y: 570, X: 570 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(285,285) Y';
			TemporalMap(285,285) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV2_1 {
		Type: CONV
		Dimensions { K: 128, C: 64, R: 3, S: 3, Y: 284, X: 284 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(142,142) Y';
			TemporalMap(142,142) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV2_2 {
		Type: CONV
		Dimensions { K: 128, C: 128, R: 3, S: 3, Y: 282, X: 282 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(141,141) Y';
			TemporalMap(141,141) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV3_1 {
		Type: CONV
		Dimensions { K: 256, C: 128, R: 3, S: 3, Y: 140, X: 140 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(70,70) Y';
			TemporalMap(70,70) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}


	Layer CONV3_2 {
		Type: CONV
		Dimensions { K: 256, C: 256, R: 3, S: 3, Y: 138, X: 138 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(69,69) Y';
			TemporalMap(69,69) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV4_1 {
		Type: CONV
		Dimensions { K: 512, C: 256, R: 3, S: 3, Y: 68, X: 68 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(34,34) Y';
			TemporalMap(34,34) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}


	Layer CONV4_2 {
		Type: CONV
		Dimensions { K: 512, C: 512, R: 3, S: 3, Y: 66, X: 66 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(33,33) Y';
			TemporalMap(33,33) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV5_1 {
		Type: CONV
		Dimensions { K: 1024, C: 512, R: 3, S: 3, Y: 32, X: 32 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(16,16) Y';
			TemporalMap(16,16) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}


	Layer CONV5_2 {
		Type: CONV
		Dimensions { K: 1024, C: 1024, R: 3, S: 3, Y: 30, X: 30 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(15,15) Y';
			TemporalMap(15,15) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;

		}
	}

	Layer TRCONV1 {
		Type: TRCONV
		Dimensions { K: 512, C: 1024, R: 2, S: 2, Y: 28, X: 28 }
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

	Layer CONV4_3 {
		Type: CONV
		Dimensions { K: 512, C: 1024, R: 3, S: 3, Y: 56, X: 56 }
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

	Layer CONV4_4 {
		Type: CONV
		Dimensions { K: 512, C: 512, R: 3, S: 3, Y: 54, X: 54 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(27,27) Y';
			TemporalMap(27,27) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;

		}
	}

	Layer TRCONV2 {
		Type: TRCONV
		Dimensions { K: 512, C: 512, R: 2, S: 2, Y: 52, X: 52 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(26,26) Y';
			TemporalMap(26,26) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;

		}
	}

	Layer CONV3_3 {
		Type: CONV
		Dimensions { K: 256, C: 512, R: 3, S: 3, Y: 104, X: 104 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(52,52) Y';
			TemporalMap(52,52) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;

		}
	}


	Layer CONV3_4 {
		Type: CONV
		Dimensions { K: 256, C: 256, R: 3, S: 3, Y: 102, X: 102 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(51,51) Y';
			TemporalMap(51,51) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;

		}
	}

	Layer TRCONV3 {
		Type: TRCONV
		Dimensions { K: 128, C: 256, R: 2, S: 2, Y: 100, X: 100 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(50,50) Y';
			TemporalMap(50,50) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}


	Layer CONV2_3 {
		Type: CONV
		Dimensions { K: 128, C: 256, R: 3, S: 3, Y: 200, X: 200 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(100,100) Y';
			TemporalMap(100,100) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV2_4 {
		Type: CONV
		Dimensions { K: 128, C: 128, R: 3, S: 3, Y: 198, X: 198 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(99,99) Y';
			TemporalMap(99,99) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer TRCONV4 {
		Type: TRCONV
		Dimensions { K: 64, C: 128, R: 2, S: 2, Y: 196, X: 196 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(98,98) Y';
			TemporalMap(98,98) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV1_3 {
		Type: CONV
		Dimensions { K: 64, C: 128, R: 3, S: 3, Y: 392, X: 392 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(196,196) Y';
			TemporalMap(196,196) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}


	Layer CONV1_4 {
		Type: CONV
		Dimensions { K: 64, C: 64, R: 3, S: 3, Y: 390, X: 390 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) C;
			TemporalMap(32,32) K;
			TemporalMap(195,195) Y';
			TemporalMap(195,195) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(32, P);
			SpatialMap(1,1) K;
		}
	}

	Layer CONV1_5 {
		Type: CONV
		Dimensions { K: 2, C: 64, R: 1, S: 1, Y: 388, X: 388 }
		Dataflow {
			// Fill your dataflow here
			SpatialMap(1,1) K;
			TemporalMap(Sz(C),Sz(C)) C;
			TemporalMap(194,194) Y';
			TemporalMap(194,194) X';
			TemporalMap(Sz(R),Sz(R)) R;
			TemporalMap(Sz(S),Sz(S)) S;
			Cluster(Sz(C), P);
			SpatialMap(1,1) C;
		}
	}
}

// Accelerator {
//  PE { NumPEs: 128; VectorWidth: 4; MultPrecision: INT8, AddPrecision: INT16 }
//  Buffer { GlobalL2: 2048, LocalL1: 64}
//  NoC {Bandwidth: 64; AvgLatency: 2}
// }
