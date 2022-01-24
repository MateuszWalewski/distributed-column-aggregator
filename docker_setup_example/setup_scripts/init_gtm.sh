#!/bin/bash





sudo mkdir $PGFILES/gtm1

sudo chown -R postgres:postgres $PGFILES/gtm1

initgtm -Z gtm -D  $PGFILES/gtm1

sudo -u postgres echo "host all  all    0.0.0.0/0  trust" >> $PGFILES/gtm1/pg_hba.conf
sudo -u postgres echo "listen_addresses='*'" >> $PGFILES/gtm1/postgresql.conf

#gtm -D $PGFILES/gtm1 $LOG_DIR/logfile_Px_gtm 2>&1 &
gtm_ctl -Z gtm -D $PGFILES/gtm1 -l $LOG_DIR/logfile_Px_gtm start

sleep 10
tail -f $LOG_DIR/logfile_Px_gtm
