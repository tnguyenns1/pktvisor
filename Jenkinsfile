pipeline {
  agent any
  stages {
    stage('Getting Started') {
      steps {
        git(url: 'git@github.com:nsone/platform.git', branch: 'develop', credentialsId: 'jenkins')
      }
    }
    stage('Final step') {
      steps {
        echo 'Final!!'
      }
    }
  }
}