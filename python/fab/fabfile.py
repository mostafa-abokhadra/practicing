from fabric.api import task, local
from invoke import run

@task
def hello(name="unknown"):
    local("echo halllaloia {}".format(name))
