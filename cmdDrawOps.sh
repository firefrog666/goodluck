#/bin/sh

#cp ~/Research/TCAD16_RFPandR/Prog/rfpandr_result/drawOps_c$1_p$2_i$3.txt .
echo $1.txt | asy -o drawOps.eps drawOps.asy && epspdf drawOps.eps
evince drawOps.pdf
# open "drawOps_c$1_p$2_i$3.pdf"
