#! /usr/bin/env bash
#

cp /vagrant/sources.list /etc/apt/
apt-get update
apt-get install -y g++ cmake openjdk-7-jdk

